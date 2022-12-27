// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: AustinPowersGUI

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_SplashScreen;
lv_obj_t * ui_SplashImage;
lv_obj_t * ui_BrowseScreen;
lv_obj_t * ui_FilesPanel;
lv_obj_t * ui_USBDeviceLabel;
lv_obj_t * ui_USBLoadIndicator;

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
void ui_SplashScreen_screen_init(void)
{
    ui_SplashScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SplashScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_SplashImage = lv_img_create(ui_SplashScreen);
    lv_img_set_src(ui_SplashImage, &ui_img_rr_png);
    lv_obj_set_width(ui_SplashImage, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SplashImage, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SplashImage, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SplashImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SplashImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

}
void ui_BrowseScreen_screen_init(void)
{
    ui_BrowseScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_BrowseScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_FilesPanel = lv_obj_create(ui_BrowseScreen);
    lv_obj_set_width(ui_FilesPanel, 148);
    lv_obj_set_height(ui_FilesPanel, 94);
    lv_obj_set_x(ui_FilesPanel, 0);
    lv_obj_set_y(ui_FilesPanel, 10);
    lv_obj_set_align(ui_FilesPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_FilesPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_FilesPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_FilesPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_USBDeviceLabel = lv_label_create(ui_BrowseScreen);
    lv_obj_set_width(ui_USBDeviceLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_USBDeviceLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_USBDeviceLabel, -24);
    lv_obj_set_y(ui_USBDeviceLabel, -48);
    lv_obj_set_align(ui_USBDeviceLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_USBDeviceLabel, "Transcend JetFlash 32GB");
    lv_obj_set_style_text_font(ui_USBDeviceLabel, &ui_font_Montserrat, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_USBLoadIndicator = lv_spinner_create(ui_BrowseScreen, 1000, 90);
    lv_obj_set_width(ui_USBLoadIndicator, 15);
    lv_obj_set_height(ui_USBLoadIndicator, 14);
    lv_obj_set_x(ui_USBLoadIndicator, 65);
    lv_obj_set_y(ui_USBLoadIndicator, -49);
    lv_obj_set_align(ui_USBLoadIndicator, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_USBLoadIndicator, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    lv_obj_set_style_arc_width(ui_USBLoadIndicator, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_SplashScreen_screen_init();
    ui_BrowseScreen_screen_init();
    lv_disp_load_scr(ui_SplashScreen);
}
