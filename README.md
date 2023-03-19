# ESP32 GPS Altimeter Variometer (M5Stack Core version)

Portage sur M5Stack Core1

Projet original : https://github.com/har-in-air/ESP32_IMU_BARO_GPS_VARIO



todo :

- Problème de taille trop importante des images .c "heading". Possibilité d'augmenter la mémoire flash disponible en précisant dans le platformio.ini : "board_build.partitions = "huge_app.csv". Car sinon la mémoire dispo est de seulement 1.3Mo sur le M5Stack Core1 !


- Erreur compilation dans nv/options.cpp : "undefined reference to" : szLogType, szAltDisplayType et szBtMsgType ? 
- Erreur compilation dans btmsg.cpp : "undefined reference to" : IsBluetoothEnabled, SupplyVoltageV, GpsCourseHeadingDeg
Solution trouvée ! : il manque la définition (et non pas la déclaration "extern" dans le ui.h). Cette déclaration figure normalement dans ui.cpp
Il faut donc adapter un nouveau ui.cpp en prenant en compte les variables originales et la nouvelle UI sur LVGL

- Attention aux conflits entre bibliothèques M5Stack et le reste du programme (notamment IMU, MPU, SPI etc.)


 

