
#include <M5Stack.h>
#include "common.h"
#include "config.h"
#include "drv/cct.h"
#include "drv/vspi.h"
#include "sensor/mpu9250.h"
#include "sensor/ringbuf.h"
#include "sensor/imu.h"
#if USE_MS5611
#include "sensor/ms5611.h"
#elif USE_BMP388
#include "sensor/bmp388.h"
#endif
#include "sensor/kalmanfilter4d.h"
#include "nv/calib.h"
#include "nv/options.h"
#include "ui/vario_audio.h"


static const char* TAG = "main";

volatile float KFAltitudeCm, KFClimbrateCps,DisplayClimbrateCps; // Cps : centimeter per second
volatile int AudioCps;
volatile float YawDeg, PitchDeg, RollDeg;
volatile SemaphoreHandle_t DrdySemaphore;
volatile bool DrdyFlag = false;


static void pinConfig();
static void vario_taskConfig();
static void vario_task(void *pvParameter);
static void main_task(void* pvParameter);

static void IRAM_ATTR drdyHandler(void);

void pinConfig() {	
    
    pinMode(pinImuCS, OUTPUT);
#if USE_MS5611    
    pinMode(pinMS5611CS, OUTPUT);
    MS5611_CS_HI();
#elif USE_BMP388    
    pinMode(pinBMP388CS, OUTPUT);
    BMP388_CS_HI();
#endif
    
    IMU_CS_HI();

    pinMode(pinDRDYINT, INPUT); // external 10K pullup
    }



static void IRAM_ATTR drdyHandler(void) {
	DrdyFlag = true;
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	xSemaphoreGiveFromISR(DrdySemaphore, &xHigherPriorityTaskWoken);
    if( xHigherPriorityTaskWoken == pdTRUE) {
        portYIELD_FROM_ISR(); // this wakes up vario_task immediately instead of on next FreeRTOS tick
		}
	
	}


static void vario_taskConfig() {
    
    M5.Lcd.clear();
    if (mpu9250_config() < 0) {
        
        M5.Lcd.println("MPU9250 config failed");
        while (1) {delayMs(100);};
        }

   
    // if calib.txt not found, enforce accel and mag calibration and write new calib.txt
    bool isAccelMagCalibRequired = !IsCalibrated;
    int counter = 300;
    while ((!isAccelMagCalibRequired) && counter--) {
   	    //lcd_printlnf(true,3,"Gyro calib in %ds",(counter+50)/100);
        M5.lcd.printf("Gyro calib in %ds\n",(counter+50)/10);
        M5.update();
        if (M5.BtnA.isPressed()) {
            // manually force accel+mag calibration by pressing BTN0 during gyro calib countdown
            isAccelMagCalibRequired = true; 
            break;
            }
        delayMs(10);	
		}
    if (isAccelMagCalibRequired) {
        counter = 8;
        while (counter--) {
            //lcd_printlnf(true,3,"Accel calib in %ds",counter+1);
            M5.lcd.printf("Accel calib in %ds\n",counter+1);
            delayMs(1000);	
            }
        //lcd_printlnf(true,3, "Calibrating Accel...");
        M5.Lcd.println("Calibrating Accel...");
        if (mpu9250_calibrateAccel() < 0) {
 	        //lcd_printlnf(true,3,"Accel calib failed");
            M5.Lcd.println("Accel calib failed");
            while (1) {delayMs(100);};
            }
        delayMs(1000);
        counter = 5;
        while (counter--) {
            //lcd_printlnf(true,3,"Mag calib in %ds",counter+1);
            M5.lcd.printf("Mag calib in %ds\n",counter+1);
            delayMs(1000);	
            }
        //lcd_printlnf(true,3,"Calibrating Mag...");
        M5.Lcd.println("Calibrating Mag...");
        if (mpu9250_calibrateMag()  < 0 ) {
 	        //lcd_printlnf(true,3,"Mag calib failed");
            M5.Lcd.println("Mag calib failed");
            }
        }
    if (isAccelMagCalibRequired) {
        counter = 3;
        while (counter--) {
            //lcd_printlnf(true,3,"Gyro calib in %ds",counter+1);
            M5.lcd.printf("Gyro calib in %ds\n",counter+1);
            }
        }
    //lcd_printlnf(true,3,"Calibrating Gyro...");
    M5.Lcd.println("Calibrating Gyro...");
    if (mpu9250_calibrateGyro() < 0) {
 	    //lcd_printlnf(true,3,"Gyro calib fail");
        M5.Lcd.println("Gyro calib failed");
        delayMs(1000);
        }
   // mpu9250_dump_noise_samples();

#if USE_MS5611
    if (ms5611_config() < 0) {
        ESP_LOGE(TAG, "error MS5611 config");
        //lcd_printlnf(true,3, "MS5611 config fail");
        M5.Lcd.println("MS5611 config fail");
        while (1) {delayMs(100);}
        }	
    ms5611_averagedSample(20);
    ESP_LOGD(TAG,"MS5611 Altitude %dm Temperature %dC", (int)(ZCmAvg_MS5611/100.0f), (int)CelsiusSample_MS5611);
    float zcm = ZCmAvg_MS5611;
    ms5611_initializeSampleStateMachine();
#elif USE_BMP388    
    if (bmp388_config() < 0) {
        ESP_LOGE(TAG, "error BMP388 config");
        //lcd_printlnf(true,3, "BMP388 config fail");
        M5.Lcd.println("BMP388 config fail");
        while (1) {delayMs(100);}
        }	
    {
    uint32_t marker =  cct_setMarker();
    bmp388_sample();
    uint32_t eus = cct_elapsedUs(marker);
    ESP_LOGD(TAG, "BMP388 sample and pa2z : %d us", eus);
    }
    
    bmp388_averaged_sample(20);
    ESP_LOGD(TAG,"BMP388 Altitude %dm Temperature %dC", (int)(ZCmAvg_BMP388/100.0f), (int)CelsiusSample_BMP388);
    float zcm = ZCmAvg_BMP388;
#endif

    // KF4D algorithm to fuse gravity-compensated acceleration and pressure altitude to estimate
    // altitude and climb/sink rate
    kalmanFilter4d_configure(1000.0f*(float)opt.kf.accelVariance, KF_ADAPT, zcm, 0.0f, 0.0f);

    //lcd_clear_frame();
    M5.Lcd.clear();
    //lcd_printlnf(true,3,"Baro Altitude %dm", (int)(zcm/100.0f));
    M5.lcd.printf("Baro Altitude %dm\n", (int)(zcm/100.0f));
    // switch to high clock frequency for sensor readout & flash writes
    vspi_setClockFreq(VSPI_CLK_HIGH_FREQHZ); 

    vaudio_config();


    ringbuf_init(); 
    }


static void vario_task(void *pvParameter) {
    float gxdps, gydps, gzdps, axmG, aymG, azmG, mx, my, mz;
    float gxNEDdps, gyNEDdps, gzNEDdps, axNEDmG, ayNEDmG, azNEDmG, mxNED, myNED, mzNED;

    ESP_LOGI(TAG, "Starting vario task on core %d with priority %d", xPortGetCoreID(), uxTaskPriorityGet(NULL));
    uint32_t clockPrevious, clockNow; // time markers for imu, baro and kalman filter
    float 	imuTimeDeltaUSecs; // time between imu samples, in microseconds
    float 	kfTimeDeltaUSecs = 0.0f; // time between kalman filter updates, in microseconds

    clockNow = clockPrevious = XTHAL_GET_CCOUNT();
    int drdyCounter = 0;   
    int baroCounter = 0;
    DrdySemaphore = xSemaphoreCreateBinary();
    attachInterrupt(pinDRDYINT, drdyHandler, RISING);

    while (1) {
        xSemaphoreTake(DrdySemaphore, portMAX_DELAY); // wait for data ready interrupt from MPU9250 (500Hz)
        clockNow = XTHAL_GET_CCOUNT();
#ifdef IMU_DEBUG
        uint32_t marker =  cct_setMarker();
        LED_ON();
#endif
        imuTimeDeltaUSecs = cct_intervalUs(clockPrevious, clockNow); // time in us since last sample
        clockPrevious = clockNow;
        drdyCounter++;
        baroCounter++;
        mpu9250_getGyroAccelMagData( &gxdps, &gydps, &gzdps, &axmG, &aymG, &azmG, &mx, &my, &mz);
        // translate from sensor axes to AHRS NED (north-east-down) right handed coordinate frame      
        axNEDmG = -aymG;
        ayNEDmG = -axmG;
        azNEDmG = azmG;
        gxNEDdps = gydps;
        gyNEDdps = gxdps;
        gzNEDdps = -gzdps;
        mxNED =  mx;
        myNED =  my;
        mzNED =  mz;
        // Use accelerometer data for determining the orientation quaternion only when accel 
        // vector magnitude is in [0.75g, 1.25g] window.
        float asqd = axNEDmG*axNEDmG + ayNEDmG*ayNEDmG + azNEDmG*azNEDmG;
        int useAccel = ((asqd > 562500.0f) && (asqd < 1562500.0f)) ? 1 : 0;	
        int useMag = true;
        imu_mahonyAHRSupdate9DOF(useAccel, useMag,((float)imuTimeDeltaUSecs)/1000000.0f, DEG2RAD(gxNEDdps), DEG2RAD(gyNEDdps), DEG2RAD(gzNEDdps), axNEDmG, ayNEDmG, azNEDmG, mxNED, myNED, mzNED);
        imu_quaternion2YawPitchRoll(q0,q1,q2,q3, (float*)&YawDeg, (float*)&PitchDeg, (float*)&RollDeg);
        float gravityCompensatedAccel = imu_gravityCompensatedAccel(axNEDmG, ayNEDmG, azNEDmG, q0, q1, q2, q3);
        ringbuf_addSample(gravityCompensatedAccel);
        kfTimeDeltaUSecs += imuTimeDeltaUSecs;
#if USE_MS5611
        if (baroCounter >= 5) { // 5*2mS = 10mS elapsed, this is the sampling period for MS5611, 
            baroCounter = 0;     // alternating between pressure and temperature samples
            int zMeasurementAvailable = ms5611_sampleStateMachine(); 
            // one altitude sample is calculated for a pair of pressure & temperature samples
			if ( zMeasurementAvailable ) { 
                // KF4 uses the acceleration data in the update phase
                float zAccelAverage = ringbuf_averageNewestSamples(10); 
                kalmanFilter4d_predict(kfTimeDeltaUSecs/1000000.0f);
                kalmanFilter4d_update(ZCmSample_MS5611, zAccelAverage, (float*)&KFAltitudeCm, (float*)&KFClimbrateCps);
                kfTimeDeltaUSecs = 0.0f;
                // LCD display shows damped climbrate
                DisplayClimbrateCps = (DisplayClimbrateCps*(float)opt.vario.varioDisplayIIR + KFClimbrateCps*(100.0f - (float)opt.vario.varioDisplayIIR))/100.0f; 
                AudioCps = INTEGER_ROUNDUP(KFClimbrateCps);
                
                vaudio_tick_handler(AudioCps);                
                    
			    
                }    
            } 
#elif USE_BMP388
        if (baroCounter >= 10) { // 10*2mS = 20mS elapsed, this is the configured sampling period for BMP388
            baroCounter = 0;     
            bmp388_sample();
            // KF4 uses the acceleration data in the update phase
            float zAccelAverage = ringbuf_averageNewestSamples(10); 
            kalmanFilter4d_predict(kfTimeDeltaUSecs/1000000.0f);
            kalmanFilter4d_update(ZCmSample_BMP388, zAccelAverage, (float*)&KFAltitudeCm, (float*)&KFClimbrateCps);
            kfTimeDeltaUSecs = 0.0f;
            // LCD display shows damped climbrate
            DisplayClimbrateCps = (DisplayClimbrateCps*(float)opt.vario.varioDisplayIIR + KFClimbrateCps*(100.0f - (float)opt.vario.varioDisplayIIR))/100.0f; 
            int32_t audioCps = INTEGER_ROUNDUP(KFClimbrateCps);
            vaudio_tick_handler(AudioCps);
		    
            }    
#endif
         
#ifdef IMU_DEBUG
        uint32_t eus = cct_elapsedUs(marker);
		LED_OFF(); // scope the led on-time to ensure worst case < 2mS
#endif
        if (drdyCounter >= 500) {
            drdyCounter = 0;
#ifdef IMU_DEBUG
            //ESP_LOGD(TAG,"%dus",eus); // need to ensure time elapsed is less than 2mS worst case
			//ESP_LOGD(TAG,"\r\nY = %d P = %d R = %d", (int)YawDeg, (int)PitchDeg, (int)RollDeg);
			//ESP_LOGD(TAG,"ba = %d ka = %d v = %d",(int)ZCmSample, (int)KFAltitudeCm, (int)KFClimbrateCps);

            // ESP_LOGD(TAG,"ax %.1f ay %.1f az %.1f", axmG, aymG, azmG);
            // ESP_LOGD(TAG,"gx %.1f gy %.1f gz %.1f", gxdps, gydps, gzdps);
            // ESP_LOGD(TAG,"mx %.1f my %.1f mz %.1f", mx, my, mz);
            // ESP_LOGD(TAG,"ax %.1f ay %.1f az %.1f", axNEDmG, ayNEDmG, azNEDmG);
            // ESP_LOGD(TAG,"gx %.1f gy %.1f gz %.1f", gxNEDdps, gyNEDdps, gzNEDdps);
            // ESP_LOGD(TAG,"mx %.1f my %.1f mz %.1f", mxNED, myNED, mzNED);

            // ESP_LOGD(TAG,"baro alt %dcm", (int)ZCmSample);
            //lcd_clear_frame();
            //lcd_printf(0,0,"a %d %d %d", (int)axmG, (int)aymG, (int)azmG);
            //lcd_printf(1,0,"g %d %d %d", (int)gxdps, (int)gydps, (int)gzdps);
            //lcd_printf(2,0,"m %d %d %d", (int)mx, (int)my, (int)mz);
            //lcd_printf(0,0,"a %d %d %d", (int)axNEDmG, (int)ayNEDmG, (int)azNEDmG);
            //lcd_printf(1,0,"g %d %d %d", (int)gxNEDdps, (int)gyNEDdps, (int)gzNEDdps);
            //lcd_printf(2,0,"m %d %d %d", (int)mxNED, (int)myNED, (int)mzNED);
            //lcd_send_frame();
#endif
            }
        }
    vTaskDelete(NULL);
    }




static void main_task(void* pvParameter) {
    pinConfig();
    
   

    // read calibration parameters from calib.txt
    calib_init();

    // set default configuration parameters, then override them with configuration parameters read from options.txt
    // so you only have to specify the parameters you want to modify, in the file options.txt
    opt_init();

   

    // VSPI bus used for MPU9250, MS5611 and 128Mbit spi flash
    // start with low clock frequency for sensor configuration
    vspi_config(pinVSCLK, pinVMOSI, pinVMISO, VSPI_CLK_CONFIG_FREQHZ);
   


     // GPS Vario mode
        

        vario_taskConfig();   	

        // vario task on core 1 needs to complete all processing within 2mS IMU data sampling period,
        // given highest priority on core 1
	    xTaskCreatePinnedToCore(&vario_task, "variotask", 4096, NULL, configMAX_PRIORITIES-1, NULL, CORE_1);
        
      
    while (1) {
        loop();
        }
    }


// loop runs on core 1 with default priority = 1
void loop() {
    

    }

// workaround for not having access to 'make menuconfig' to configure the stack size for the
// setup and loop task is to create a new main task with desired stack size, and then delete setup 
// task. 
// Core 0 : ui, GPS, Bluetooth tasks
// Core 1 : setup() + loop(), wifi config / vario task
void setup() {
    M5.begin();

    xTaskCreatePinnedToCore(&main_task, "main_task", 16384, NULL, configMAX_PRIORITIES-4, NULL, CORE_1);
    vTaskDelete(NULL);
    }
