// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.1
// LVGL VERSION: 8.2.0
// PROJECT: SquareLine_Project_vario

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_NAV;
lv_obj_t * ui_Main1;
lv_obj_t * ui_Panel_boussole;
lv_obj_t * ui_Couronne_boussole;
lv_obj_t * ui_Pinule_orange;
lv_obj_t * ui_Pinule_bleu;
lv_obj_t * ui_Fleche_boussole;
lv_obj_t * ui_Label_cap;
lv_obj_t * ui_Label_waypoint;
lv_obj_t * ui_Label_RTH;
lv_obj_t * ui_Panel_NAV_superieur;
lv_obj_t * ui_Label_NAV;
lv_obj_t * ui_Label_status_GPS;
lv_obj_t * ui_Label_temperature_ambiante;
lv_obj_t * ui_Arc_vario;
lv_obj_t * ui_l1;
lv_obj_t * ui_Label11;
lv_obj_t * ui_Label12;
lv_obj_t * ui_Label13;
lv_obj_t * ui_Label15;
lv_obj_t * ui_Label20;
lv_obj_t * ui_Label21;
lv_obj_t * ui_Label22;
lv_obj_t * ui_Label23;
lv_obj_t * ui_Label25;
lv_obj_t * ui_Panel_info_NAV_droit;
lv_obj_t * ui_Label_Alt_texte;
lv_obj_t * ui_Label_Alt;
lv_obj_t * ui_Label_temps;
lv_obj_t * ui_Label_temps_texte;
lv_obj_t * ui_Label_finesse_texte;
lv_obj_t * ui_Label_finesse;
lv_obj_t * ui_Label_vitesse_sol_texte;
lv_obj_t * ui_Label_vitesse_sol;
lv_obj_t * ui_Label_kmh;
lv_obj_t * ui_ligne4;
lv_obj_t * ui_ligne3;
lv_obj_t * ui_ligne1;
lv_obj_t * ui_ligne2;
lv_obj_t * ui_Label_Alt_hold_texte1;
lv_obj_t * ui_Label_vario_moyen_texte;
lv_obj_t * ui_Label_vario_moyen;
lv_obj_t * ui_Label_unite_metre_par_seconde;
lv_obj_t * ui_ligne5;
lv_obj_t * ui_Label_vario;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_NAV_screen_init(void)
{
    ui_NAV = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_NAV, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_NAV, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NAV, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Main1 = lv_obj_create(ui_NAV);
    lv_obj_set_width(ui_Main1, lv_pct(100));
    lv_obj_set_height(ui_Main1, lv_pct(100));
    lv_obj_set_align(ui_Main1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Main1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Main1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Main1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Main1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Main1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Main1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Main1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel_boussole = lv_obj_create(ui_Main1);
    lv_obj_set_width(ui_Panel_boussole, 206);
    lv_obj_set_height(ui_Panel_boussole, 228);
    lv_obj_set_x(ui_Panel_boussole, -26);
    lv_obj_set_y(ui_Panel_boussole, 14);
    lv_obj_set_align(ui_Panel_boussole, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel_boussole, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel_boussole, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel_boussole, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel_boussole, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Couronne_boussole = lv_img_create(ui_Panel_boussole);
    lv_img_set_src(ui_Couronne_boussole, &ui_img_heading_couronne_png);
    lv_obj_set_width(ui_Couronne_boussole, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Couronne_boussole, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Couronne_boussole, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Couronne_boussole, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Couronne_boussole, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_angle(ui_Couronne_boussole, 120);

    ui_Pinule_orange = lv_img_create(ui_Panel_boussole);
    lv_img_set_src(ui_Pinule_orange, &ui_img_heading_pinule_png);
    lv_obj_set_width(ui_Pinule_orange, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Pinule_orange, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Pinule_orange, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Pinule_orange, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Pinule_orange, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Pinule_bleu = lv_img_create(ui_Panel_boussole);
    lv_img_set_src(ui_Pinule_bleu, &ui_img_heading_pinule_bleu_png);
    lv_obj_set_width(ui_Pinule_bleu, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Pinule_bleu, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Pinule_bleu, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Pinule_bleu, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Pinule_bleu, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_angle(ui_Pinule_bleu, 900);

    ui_Fleche_boussole = lv_img_create(ui_Panel_boussole);
    lv_img_set_src(ui_Fleche_boussole, &ui_img_heading_fleche_ligne_de_foi_png);
    lv_obj_set_width(ui_Fleche_boussole, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Fleche_boussole, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Fleche_boussole, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Fleche_boussole, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Fleche_boussole, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label_cap = lv_label_create(ui_Panel_boussole);
    lv_obj_set_width(ui_Label_cap, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_cap, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_cap, 0);
    lv_obj_set_y(ui_Label_cap, 43);
    lv_obj_set_align(ui_Label_cap, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label_cap, "347");
    lv_obj_set_style_text_color(ui_Label_cap, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_cap, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_cap, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Label_cap, lv_color_hex(0x353535), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Label_cap, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Label_cap, lv_color_hex(0x989898), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Label_cap, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Label_cap, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Label_cap, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_waypoint = lv_label_create(ui_Panel_boussole);
    lv_obj_set_width(ui_Label_waypoint, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_waypoint, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_waypoint, -41);
    lv_obj_set_y(ui_Label_waypoint, -12);
    lv_obj_set_align(ui_Label_waypoint, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label_waypoint, "0.89km");
    lv_obj_add_flag(ui_Label_waypoint, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_color(ui_Label_waypoint, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_waypoint, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui_Label_waypoint, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_Label_waypoint, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_waypoint, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Label_waypoint, lv_color_hex(0xFF6A00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Label_waypoint, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Label_waypoint, lv_color_hex(0xFF6A00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Label_waypoint, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Label_waypoint, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Label_waypoint, lv_color_hex(0xFF6A00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Label_waypoint, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Label_waypoint, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Label_waypoint, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_RTH = lv_label_create(ui_Panel_boussole);
    lv_obj_set_width(ui_Label_RTH, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_RTH, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_RTH, 42);
    lv_obj_set_y(ui_Label_RTH, -12);
    lv_obj_set_align(ui_Label_RTH, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label_RTH, "2.6km");
    lv_obj_add_flag(ui_Label_RTH, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_color(ui_Label_RTH, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_RTH, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_RTH, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Label_RTH, lv_color_hex(0x0095FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Label_RTH, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Label_RTH, lv_color_hex(0x0095FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Label_RTH, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Label_RTH, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Label_RTH, lv_color_hex(0x0095FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Label_RTH, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Label_RTH, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Label_RTH, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel_NAV_superieur = lv_obj_create(ui_Main1);
    lv_obj_set_width(ui_Panel_NAV_superieur, 320);
    lv_obj_set_height(ui_Panel_NAV_superieur, 12);
    lv_obj_set_x(ui_Panel_NAV_superieur, 0);
    lv_obj_set_y(ui_Panel_NAV_superieur, -13);
    lv_obj_set_align(ui_Panel_NAV_superieur, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Panel_NAV_superieur, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel_NAV_superieur, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel_NAV_superieur, lv_color_hex(0x343434), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel_NAV_superieur, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel_NAV_superieur, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel_NAV_superieur, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_NAV = lv_label_create(ui_Panel_NAV_superieur);
    lv_obj_set_width(ui_Label_NAV, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_NAV, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label_NAV, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label_NAV, "NAV");
    lv_obj_set_style_text_color(ui_Label_NAV, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_NAV, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Label_NAV, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_NAV, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_status_GPS = lv_label_create(ui_Panel_NAV_superieur);
    lv_obj_set_width(ui_Label_status_GPS, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_status_GPS, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_status_GPS, 9);
    lv_obj_set_y(ui_Label_status_GPS, 0);
    lv_obj_set_align(ui_Label_status_GPS, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label_status_GPS, "GPS OK");
    lv_obj_set_style_text_color(ui_Label_status_GPS, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_status_GPS, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Label_status_GPS, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_status_GPS, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_temperature_ambiante = lv_label_create(ui_Panel_NAV_superieur);
    lv_obj_set_width(ui_Label_temperature_ambiante, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_temperature_ambiante, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label_temperature_ambiante, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label_temperature_ambiante, "23.5°C");
    lv_obj_set_style_text_color(ui_Label_temperature_ambiante, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_temperature_ambiante, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Label_temperature_ambiante, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_temperature_ambiante, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Arc_vario = lv_arc_create(ui_Main1);
    lv_obj_set_width(ui_Arc_vario, 305);
    lv_obj_set_height(ui_Arc_vario, 231);
    lv_obj_set_x(ui_Arc_vario, 9);
    lv_obj_set_y(ui_Arc_vario, 15);
    lv_obj_set_align(ui_Arc_vario, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_Arc_vario, -50, 50);
    lv_arc_set_value(ui_Arc_vario, 30);
    lv_arc_set_bg_angles(ui_Arc_vario, 220, 320);
    lv_arc_set_mode(ui_Arc_vario, LV_ARC_MODE_SYMMETRICAL);
    lv_arc_set_rotation(ui_Arc_vario, -90);
    lv_obj_set_style_bg_color(ui_Arc_vario, lv_color_hex(0x343434), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc_vario, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_Arc_vario, lv_color_hex(0x343434), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc_vario, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc_vario, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui_Arc_vario, false, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_Arc_vario, lv_color_hex(0x3FE782), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc_vario, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc_vario, 15, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui_Arc_vario, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Arc_vario, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc_vario, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Arc_vario, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Arc_vario, 20, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Arc_vario, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Arc_vario, 20, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_l1 = lv_label_create(ui_Arc_vario);
    lv_obj_set_width(ui_l1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_l1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_l1, -145);
    lv_obj_set_y(ui_l1, 0);
    lv_obj_set_align(ui_l1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_l1, "---");
    lv_obj_set_style_text_color(ui_l1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_l1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label11 = lv_label_create(ui_Arc_vario);
    lv_obj_set_width(ui_Label11, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label11, -143);
    lv_obj_set_y(ui_Label11, -19);
    lv_obj_set_align(ui_Label11, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label11, "1");
    lv_obj_set_style_text_color(ui_Label11, lv_color_hex(0x353535), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label11, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label12 = lv_label_create(ui_Arc_vario);
    lv_obj_set_width(ui_Label12, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label12, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label12, -138);
    lv_obj_set_y(ui_Label12, -37);
    lv_obj_set_align(ui_Label12, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label12, "2");
    lv_obj_set_style_text_color(ui_Label12, lv_color_hex(0x353535), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label12, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label13 = lv_label_create(ui_Arc_vario);
    lv_obj_set_width(ui_Label13, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label13, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label13, -130);
    lv_obj_set_y(ui_Label13, -54);
    lv_obj_set_align(ui_Label13, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label13, "3");
    lv_obj_set_style_text_color(ui_Label13, lv_color_hex(0x353535), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label13, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label15 = lv_label_create(ui_Arc_vario);
    lv_obj_set_width(ui_Label15, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label15, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label15, -121);
    lv_obj_set_y(ui_Label15, -69);
    lv_obj_set_align(ui_Label15, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label15, "4");
    lv_obj_set_style_text_color(ui_Label15, lv_color_hex(0x353535), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label15, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label15, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label20 = lv_label_create(ui_Arc_vario);
    lv_obj_set_width(ui_Label20, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label20, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label20, -143);
    lv_obj_set_y(ui_Label20, 19);
    lv_obj_set_align(ui_Label20, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label20, "1");
    lv_obj_set_style_text_color(ui_Label20, lv_color_hex(0x353535), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label20, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label20, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label21 = lv_label_create(ui_Arc_vario);
    lv_obj_set_width(ui_Label21, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label21, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label21, -137);
    lv_obj_set_y(ui_Label21, 37);
    lv_obj_set_align(ui_Label21, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label21, "2");
    lv_obj_set_style_text_color(ui_Label21, lv_color_hex(0x353535), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label21, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label21, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label22 = lv_label_create(ui_Arc_vario);
    lv_obj_set_width(ui_Label22, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label22, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label22, -130);
    lv_obj_set_y(ui_Label22, 54);
    lv_obj_set_align(ui_Label22, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label22, "3");
    lv_obj_set_style_text_color(ui_Label22, lv_color_hex(0x353535), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label22, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label22, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label23 = lv_label_create(ui_Arc_vario);
    lv_obj_set_width(ui_Label23, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label23, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label23, -121);
    lv_obj_set_y(ui_Label23, 68);
    lv_obj_set_align(ui_Label23, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label23, "4");
    lv_obj_set_style_text_color(ui_Label23, lv_color_hex(0x353535), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label23, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label23, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label25 = lv_label_create(ui_Arc_vario);
    lv_obj_set_width(ui_Label25, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label25, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label25, -144);
    lv_obj_set_y(ui_Label25, 5);
    lv_obj_set_align(ui_Label25, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label25, "-");
    lv_obj_set_style_text_color(ui_Label25, lv_color_hex(0x353535), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label25, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label25, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel_info_NAV_droit = lv_obj_create(ui_Main1);
    lv_obj_set_width(ui_Panel_info_NAV_droit, 125);
    lv_obj_set_height(ui_Panel_info_NAV_droit, 245);
    lv_obj_set_x(ui_Panel_info_NAV_droit, 14);
    lv_obj_set_y(ui_Panel_info_NAV_droit, 15);
    lv_obj_set_align(ui_Panel_info_NAV_droit, LV_ALIGN_RIGHT_MID);
    lv_obj_clear_flag(ui_Panel_info_NAV_droit, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel_info_NAV_droit, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel_info_NAV_droit, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel_info_NAV_droit, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Alt_texte = lv_label_create(ui_Panel_info_NAV_droit);
    lv_obj_set_width(ui_Label_Alt_texte, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Alt_texte, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_Alt_texte, 10);
    lv_obj_set_y(ui_Label_Alt_texte, -12);
    lv_obj_set_align(ui_Label_Alt_texte, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Label_Alt_texte, "ALT");
    lv_obj_set_style_text_color(ui_Label_Alt_texte, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Alt_texte, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Alt_texte, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Alt = lv_label_create(ui_Panel_info_NAV_droit);
    lv_obj_set_width(ui_Label_Alt, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Alt, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_Alt, 13);
    lv_obj_set_y(ui_Label_Alt, 5);
    lv_obj_set_align(ui_Label_Alt, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Label_Alt, "1563m");
    lv_obj_set_style_text_color(ui_Label_Alt, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Alt, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Alt, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_temps = lv_label_create(ui_Panel_info_NAV_droit);
    lv_obj_set_width(ui_Label_temps, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_temps, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_temps, 10);
    lv_obj_set_y(ui_Label_temps, 178);
    lv_obj_set_align(ui_Label_temps, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Label_temps, "09:56");
    lv_obj_set_style_text_color(ui_Label_temps, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_temps, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_temps, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Label_temps, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Label_temps, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_temps_texte = lv_label_create(ui_Panel_info_NAV_droit);
    lv_obj_set_width(ui_Label_temps_texte, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_temps_texte, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_temps_texte, 7);
    lv_obj_set_y(ui_Label_temps_texte, 161);
    lv_obj_set_align(ui_Label_temps_texte, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Label_temps_texte, "TIME");
    lv_obj_set_style_text_color(ui_Label_temps_texte, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_temps_texte, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_temps_texte, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_finesse_texte = lv_label_create(ui_Panel_info_NAV_droit);
    lv_obj_set_width(ui_Label_finesse_texte, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_finesse_texte, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_finesse_texte, 8);
    lv_obj_set_y(ui_Label_finesse_texte, 43);
    lv_obj_set_align(ui_Label_finesse_texte, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Label_finesse_texte, "G/R");
    lv_obj_set_style_text_color(ui_Label_finesse_texte, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_finesse_texte, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_finesse_texte, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_finesse = lv_label_create(ui_Panel_info_NAV_droit);
    lv_obj_set_width(ui_Label_finesse, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_finesse, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_finesse, 10);
    lv_obj_set_y(ui_Label_finesse, 60);
    lv_obj_set_align(ui_Label_finesse, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Label_finesse, "18");
    lv_obj_set_style_text_color(ui_Label_finesse, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_finesse, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_finesse, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_vitesse_sol_texte = lv_label_create(ui_Panel_info_NAV_droit);
    lv_obj_set_width(ui_Label_vitesse_sol_texte, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_vitesse_sol_texte, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_vitesse_sol_texte, 8);
    lv_obj_set_y(ui_Label_vitesse_sol_texte, 98);
    lv_obj_set_align(ui_Label_vitesse_sol_texte, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Label_vitesse_sol_texte, "GS");
    lv_obj_set_style_text_color(ui_Label_vitesse_sol_texte, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_vitesse_sol_texte, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_vitesse_sol_texte, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_vitesse_sol = lv_label_create(ui_Panel_info_NAV_droit);
    lv_obj_set_width(ui_Label_vitesse_sol, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_vitesse_sol, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_vitesse_sol, -18);
    lv_obj_set_y(ui_Label_vitesse_sol, 119);
    lv_obj_set_align(ui_Label_vitesse_sol, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Label_vitesse_sol, "34");
    lv_obj_set_style_text_color(ui_Label_vitesse_sol, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_vitesse_sol, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_vitesse_sol, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_kmh = lv_label_create(ui_Panel_info_NAV_droit);
    lv_obj_set_width(ui_Label_kmh, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_kmh, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_kmh, 11);
    lv_obj_set_y(ui_Label_kmh, 120);
    lv_obj_set_align(ui_Label_kmh, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Label_kmh, "km\n  h");
    lv_obj_set_style_text_color(ui_Label_kmh, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_kmh, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_kmh, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ligne4 = lv_obj_create(ui_Panel_info_NAV_droit);
    lv_obj_set_width(ui_ligne4, 22);
    lv_obj_set_height(ui_ligne4, 2);
    lv_obj_set_x(ui_ligne4, 48);
    lv_obj_set_y(ui_ligne4, 32);
    lv_obj_set_align(ui_ligne4, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ligne4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ligne3 = lv_obj_create(ui_Panel_info_NAV_droit);
    lv_obj_set_width(ui_ligne3, 129);
    lv_obj_set_height(ui_ligne3, 2);
    lv_obj_set_x(ui_ligne3, 36);
    lv_obj_set_y(ui_ligne3, 53);
    lv_obj_set_align(ui_ligne3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ligne3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ligne3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ligne3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ligne3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_ligne3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_ligne3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_ligne3, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_ligne3, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ligne3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ligne1 = lv_obj_create(ui_Panel_info_NAV_droit);
    lv_obj_set_width(ui_ligne1, 144);
    lv_obj_set_height(ui_ligne1, 2);
    lv_obj_set_x(ui_ligne1, 40);
    lv_obj_set_y(ui_ligne1, -68);
    lv_obj_set_align(ui_ligne1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ligne1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ligne1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ligne1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ligne1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_ligne1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_ligne1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_ligne1, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_ligne1, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ligne1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ligne2 = lv_obj_create(ui_Panel_info_NAV_droit);
    lv_obj_set_width(ui_ligne2, 96);
    lv_obj_set_height(ui_ligne2, 2);
    lv_obj_set_x(ui_ligne2, 39);
    lv_obj_set_y(ui_ligne2, -12);
    lv_obj_set_align(ui_ligne2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ligne2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ligne2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ligne2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ligne2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_ligne2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_ligne2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_ligne2, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_ligne2, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ligne2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Alt_hold_texte1 = lv_label_create(ui_Panel_info_NAV_droit);
    lv_obj_set_width(ui_Label_Alt_hold_texte1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Alt_hold_texte1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_Alt_hold_texte1, -30);
    lv_obj_set_y(ui_Label_Alt_hold_texte1, -12);
    lv_obj_set_align(ui_Label_Alt_hold_texte1, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Label_Alt_hold_texte1, "HOLD");
    lv_obj_set_style_text_color(ui_Label_Alt_hold_texte1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Alt_hold_texte1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui_Label_Alt_hold_texte1, -2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_Label_Alt_hold_texte1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Alt_hold_texte1, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Label_Alt_hold_texte1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Label_Alt_hold_texte1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Label_Alt_hold_texte1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_vario_moyen_texte = lv_label_create(ui_Main1);
    lv_obj_set_width(ui_Label_vario_moyen_texte, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_vario_moyen_texte, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_vario_moyen_texte, -268);
    lv_obj_set_y(ui_Label_vario_moyen_texte, 187);
    lv_obj_set_align(ui_Label_vario_moyen_texte, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Label_vario_moyen_texte, "AVG");
    lv_obj_set_style_text_color(ui_Label_vario_moyen_texte, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_vario_moyen_texte, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_vario_moyen_texte, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_vario_moyen = lv_label_create(ui_Main1);
    lv_obj_set_width(ui_Label_vario_moyen, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_vario_moyen, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_vario_moyen, -255);
    lv_obj_set_y(ui_Label_vario_moyen, 201);
    lv_obj_set_align(ui_Label_vario_moyen, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Label_vario_moyen, "+3.2");
    lv_obj_set_style_text_color(ui_Label_vario_moyen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_vario_moyen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_vario_moyen, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_unite_metre_par_seconde = lv_label_create(ui_Main1);
    lv_obj_set_width(ui_Label_unite_metre_par_seconde, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_unite_metre_par_seconde, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_unite_metre_par_seconde, -282);
    lv_obj_set_y(ui_Label_unite_metre_par_seconde, 33);
    lv_obj_set_align(ui_Label_unite_metre_par_seconde, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Label_unite_metre_par_seconde, "m\n s");
    lv_obj_set_style_text_color(ui_Label_unite_metre_par_seconde, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_unite_metre_par_seconde, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_unite_metre_par_seconde, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ligne5 = lv_obj_create(ui_Main1);
    lv_obj_set_width(ui_ligne5, 15);
    lv_obj_set_height(ui_ligne5, 2);
    lv_obj_set_x(ui_ligne5, -144);
    lv_obj_set_y(ui_ligne5, -56);
    lv_obj_set_align(ui_ligne5, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ligne5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label_vario = lv_label_create(ui_Main1);
    lv_obj_set_width(ui_Label_vario, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_vario, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_vario, -237);
    lv_obj_set_y(ui_Label_vario, -4);
    lv_obj_set_align(ui_Label_vario, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Label_vario, "+2.7");
    lv_obj_set_style_text_color(ui_Label_vario, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_vario, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui_Label_vario, -3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_Label_vario, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Label_vario, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_vario, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Label_vario, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Label_vario, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_NAV_screen_init();
    lv_disp_load_scr(ui_NAV);
}
