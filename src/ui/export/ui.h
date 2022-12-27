// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: AustinPowersGUI

#ifndef _AUSTINPOWERSGUI_UI_H
#define _AUSTINPOWERSGUI_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

extern lv_obj_t * ui_SplashScreen;
extern lv_obj_t * ui_SplashImage;
extern lv_obj_t * ui_BrowseScreen;
extern lv_obj_t * ui_FilesPanel;
extern lv_obj_t * ui_USBDeviceLabel;
extern lv_obj_t * ui_USBLoadIndicator;


LV_IMG_DECLARE(ui_img_rr_png);    // assets\rr.png


LV_FONT_DECLARE(ui_font_Montserrat);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
