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
extern lv_obj_t * ui_SplashScreen_Image;
extern lv_obj_t * ui_BrowseScreen;
extern lv_obj_t * ui_BrowseScreen_USBLabel;
extern lv_obj_t * ui_BrowseScreen_FilesPanel;
extern lv_obj_t * ui_BrowseScreen_USBIndicator;
extern lv_obj_t * ui_BrowseScreen_PathLabel;
extern lv_obj_t * ui_MixerScreen;
extern lv_obj_t * ui_MixerScreen_DeckA_TrackLabel;
extern lv_obj_t * ui_MixerScreen_DeckA_ArtistLabel;
extern lv_obj_t * ui_MixerScreen_DeckA_BPMLabel;
extern lv_obj_t * ui_MixerScreen_DeckA_Waveform;
extern lv_obj_t * ui_MixerScreen_DeckB_Waveform;
extern lv_obj_t * ui_MixerScreen_DeckB_TrackLabel;
extern lv_obj_t * ui_MixerScreen_DeckB_ArtistLabel;
extern lv_obj_t * ui_MixerScreen_DeckB_BPMLabel;
extern lv_obj_t * ui_DiagScreen;
extern lv_obj_t * ui_DiagScreen_Label;


LV_IMG_DECLARE(ui_img_rr_png);    // assets\rr.png


LV_FONT_DECLARE(ui_font_Inter11);
LV_FONT_DECLARE(ui_font_Inter11Bold);
LV_FONT_DECLARE(ui_font_Inter8);
LV_FONT_DECLARE(ui_font_Inter14);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
