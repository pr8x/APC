// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: AustinPowersGUI

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_SplashScreen;
lv_obj_t * ui_SplashScreen_Image;
lv_obj_t * ui_BrowseScreen;
lv_obj_t * ui_BrowseScreen_USBLabel;
lv_obj_t * ui_BrowseScreen_FilesPanel;
lv_obj_t * ui_BrowseScreen_USBIndicator;
lv_obj_t * ui_MixerScreen;
lv_obj_t * ui_MixerScreen_DeckA_TrackLabel;
lv_obj_t * ui_MixerScreen_DeckA_ArtistLabel;
lv_obj_t * ui_MixerScreen_DeckA_BPMLabel;
lv_obj_t * ui_MixerScreen_DeckA_Waveform;
lv_obj_t * ui_MixerScreen_DeckB_Waveform;
lv_obj_t * ui_MixerScreen_DeckB_TrackLabel;
lv_obj_t * ui_MixerScreen_DeckB_ArtistLabel;
lv_obj_t * ui_MixerScreen_DeckB_BPMLabel;
lv_obj_t * ui_DiagScreen;
lv_obj_t * ui_DiagScreen_Label;
lv_obj_t * ui_DiagScreen_Chart;

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

    ui_SplashScreen_Image = lv_img_create(ui_SplashScreen);
    lv_img_set_src(ui_SplashScreen_Image, &ui_img_rr_png);
    lv_obj_set_width(ui_SplashScreen_Image, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SplashScreen_Image, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SplashScreen_Image, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SplashScreen_Image, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SplashScreen_Image, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

}
void ui_BrowseScreen_screen_init(void)
{
    ui_BrowseScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_BrowseScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_BrowseScreen_USBLabel = lv_label_create(ui_BrowseScreen);
    lv_obj_set_height(ui_BrowseScreen_USBLabel, 16);
    lv_obj_set_width(ui_BrowseScreen_USBLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_BrowseScreen_USBLabel, 9);
    lv_obj_set_y(ui_BrowseScreen_USBLabel, 8);
    lv_label_set_text(ui_BrowseScreen_USBLabel, "JetFlash USB 32GB\n\n");
    lv_obj_set_style_text_font(ui_BrowseScreen_USBLabel, &ui_font_Inter11, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BrowseScreen_FilesPanel = lv_list_create(ui_BrowseScreen);
    lv_obj_set_width(ui_BrowseScreen_FilesPanel, 142);
    lv_obj_set_height(ui_BrowseScreen_FilesPanel, 89);
    lv_obj_set_x(ui_BrowseScreen_FilesPanel, 1);
    lv_obj_set_y(ui_BrowseScreen_FilesPanel, -10);
    lv_obj_set_align(ui_BrowseScreen_FilesPanel, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(ui_BrowseScreen_FilesPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BrowseScreen_FilesPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BrowseScreen_FilesPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BrowseScreen_USBIndicator = lv_spinner_create(ui_BrowseScreen, 1000, 90);
    lv_obj_set_width(ui_BrowseScreen_USBIndicator, 14);
    lv_obj_set_height(ui_BrowseScreen_USBIndicator, 14);
    lv_obj_set_x(ui_BrowseScreen_USBIndicator, -11);
    lv_obj_set_y(ui_BrowseScreen_USBIndicator, 7);
    lv_obj_set_align(ui_BrowseScreen_USBIndicator, LV_ALIGN_TOP_RIGHT);
    lv_obj_clear_flag(ui_BrowseScreen_USBIndicator, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    lv_obj_set_style_arc_width(ui_BrowseScreen_USBIndicator, 1, LV_PART_INDICATOR | LV_STATE_DEFAULT);

}
void ui_MixerScreen_screen_init(void)
{
    ui_MixerScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_MixerScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_MixerScreen_DeckA_TrackLabel = lv_label_create(ui_MixerScreen);
    lv_obj_set_width(ui_MixerScreen_DeckA_TrackLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MixerScreen_DeckA_TrackLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MixerScreen_DeckA_TrackLabel, 5);
    lv_obj_set_y(ui_MixerScreen_DeckA_TrackLabel, 5);
    lv_label_set_long_mode(ui_MixerScreen_DeckA_TrackLabel, LV_LABEL_LONG_SCROLL);
    lv_label_set_text(ui_MixerScreen_DeckA_TrackLabel, "Pressor 2600 (Original Mix)");
    lv_obj_set_style_text_font(ui_MixerScreen_DeckA_TrackLabel, &ui_font_Inter11, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MixerScreen_DeckA_ArtistLabel = lv_label_create(ui_MixerScreen);
    lv_obj_set_width(ui_MixerScreen_DeckA_ArtistLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MixerScreen_DeckA_ArtistLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MixerScreen_DeckA_ArtistLabel, 5);
    lv_obj_set_y(ui_MixerScreen_DeckA_ArtistLabel, 20);
    lv_label_set_long_mode(ui_MixerScreen_DeckA_ArtistLabel, LV_LABEL_LONG_SCROLL);
    lv_label_set_text(ui_MixerScreen_DeckA_ArtistLabel, "SAMOH");
    lv_obj_set_style_text_color(ui_MixerScreen_DeckA_ArtistLabel, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_MixerScreen_DeckA_ArtistLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_MixerScreen_DeckA_ArtistLabel, &ui_font_Inter11, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MixerScreen_DeckA_BPMLabel = lv_label_create(ui_MixerScreen);
    lv_obj_set_width(ui_MixerScreen_DeckA_BPMLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MixerScreen_DeckA_BPMLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MixerScreen_DeckA_BPMLabel, -5);
    lv_obj_set_y(ui_MixerScreen_DeckA_BPMLabel, 22);
    lv_obj_set_align(ui_MixerScreen_DeckA_BPMLabel, LV_ALIGN_TOP_RIGHT);
    lv_label_set_long_mode(ui_MixerScreen_DeckA_BPMLabel, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_MixerScreen_DeckA_BPMLabel, "145");
    lv_obj_set_style_text_color(ui_MixerScreen_DeckA_BPMLabel, lv_color_hex(0x02D23E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_MixerScreen_DeckA_BPMLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_MixerScreen_DeckA_BPMLabel, &ui_font_Inter11, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MixerScreen_DeckA_Waveform = lv_obj_create(ui_MixerScreen);
    lv_obj_set_height(ui_MixerScreen_DeckA_Waveform, 24);
    lv_obj_set_width(ui_MixerScreen_DeckA_Waveform, lv_pct(100));
    lv_obj_set_x(ui_MixerScreen_DeckA_Waveform, 0);
    lv_obj_set_y(ui_MixerScreen_DeckA_Waveform, -12);
    lv_obj_set_align(ui_MixerScreen_DeckA_Waveform, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(ui_MixerScreen_DeckA_Waveform, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_MixerScreen_DeckA_Waveform, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_MixerScreen_DeckA_Waveform, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MixerScreen_DeckB_Waveform = lv_obj_create(ui_MixerScreen);
    lv_obj_set_height(ui_MixerScreen_DeckB_Waveform, 24);
    lv_obj_set_width(ui_MixerScreen_DeckB_Waveform, lv_pct(100));
    lv_obj_set_x(ui_MixerScreen_DeckB_Waveform, 0);
    lv_obj_set_y(ui_MixerScreen_DeckB_Waveform, 12);
    lv_obj_set_align(ui_MixerScreen_DeckB_Waveform, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(ui_MixerScreen_DeckB_Waveform, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_MixerScreen_DeckB_Waveform, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_MixerScreen_DeckB_Waveform, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_MixerScreen_DeckB_Waveform, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_MixerScreen_DeckB_Waveform, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_MixerScreen_DeckB_Waveform, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MixerScreen_DeckB_TrackLabel = lv_label_create(ui_MixerScreen);
    lv_obj_set_width(ui_MixerScreen_DeckB_TrackLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MixerScreen_DeckB_TrackLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MixerScreen_DeckB_TrackLabel, 5);
    lv_obj_set_y(ui_MixerScreen_DeckB_TrackLabel, -20);
    lv_obj_set_align(ui_MixerScreen_DeckB_TrackLabel, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_long_mode(ui_MixerScreen_DeckB_TrackLabel, LV_LABEL_LONG_SCROLL);
    lv_label_set_text(ui_MixerScreen_DeckB_TrackLabel, "Make Sense");
    lv_obj_set_style_text_font(ui_MixerScreen_DeckB_TrackLabel, &ui_font_Inter11, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MixerScreen_DeckB_ArtistLabel = lv_label_create(ui_MixerScreen);
    lv_obj_set_width(ui_MixerScreen_DeckB_ArtistLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MixerScreen_DeckB_ArtistLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MixerScreen_DeckB_ArtistLabel, 5);
    lv_obj_set_y(ui_MixerScreen_DeckB_ArtistLabel, -5);
    lv_obj_set_align(ui_MixerScreen_DeckB_ArtistLabel, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_long_mode(ui_MixerScreen_DeckB_ArtistLabel, LV_LABEL_LONG_SCROLL);
    lv_label_set_text(ui_MixerScreen_DeckB_ArtistLabel, "VBL7");
    lv_obj_set_style_text_color(ui_MixerScreen_DeckB_ArtistLabel, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_MixerScreen_DeckB_ArtistLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_MixerScreen_DeckB_ArtistLabel, &ui_font_Inter11, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MixerScreen_DeckB_BPMLabel = lv_label_create(ui_MixerScreen);
    lv_obj_set_width(ui_MixerScreen_DeckB_BPMLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MixerScreen_DeckB_BPMLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MixerScreen_DeckB_BPMLabel, -4);
    lv_obj_set_y(ui_MixerScreen_DeckB_BPMLabel, -4);
    lv_obj_set_align(ui_MixerScreen_DeckB_BPMLabel, LV_ALIGN_BOTTOM_RIGHT);
    lv_label_set_long_mode(ui_MixerScreen_DeckB_BPMLabel, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_MixerScreen_DeckB_BPMLabel, "145");
    lv_obj_set_style_text_color(ui_MixerScreen_DeckB_BPMLabel, lv_color_hex(0x02D23E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_MixerScreen_DeckB_BPMLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_MixerScreen_DeckB_BPMLabel, &ui_font_Inter11, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_DiagScreen_screen_init(void)
{
    ui_DiagScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_DiagScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_DiagScreen_Label = lv_label_create(ui_DiagScreen);
    lv_obj_set_width(ui_DiagScreen_Label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_DiagScreen_Label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_DiagScreen_Label, 10);
    lv_obj_set_y(ui_DiagScreen_Label, 12);
    lv_label_set_text(ui_DiagScreen_Label, "Audio CPU: 40%\nAudio Memory: 1KB\nUptime: 2h 44m 10s\n");
    lv_obj_set_style_text_font(ui_DiagScreen_Label, &ui_font_Inter11, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DiagScreen_Chart = lv_chart_create(ui_DiagScreen);
    lv_obj_set_width(ui_DiagScreen_Chart, 142);
    lv_obj_set_height(ui_DiagScreen_Chart, 42);
    lv_obj_set_x(ui_DiagScreen_Chart, 1);
    lv_obj_set_y(ui_DiagScreen_Chart, -13);
    lv_obj_set_align(ui_DiagScreen_Chart, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_style_radius(ui_DiagScreen_Chart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_DiagScreen_Chart, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_SplashScreen_screen_init();
    ui_BrowseScreen_screen_init();
    ui_MixerScreen_screen_init();
    ui_DiagScreen_screen_init();
    lv_disp_load_scr(ui_SplashScreen);
}
