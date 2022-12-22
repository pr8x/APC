#include <Adafruit_GFX.h>        // Core graphics library
#include <FS.h>
#include <Adafruit_LvGL_Glue.h>  // Glue library header INCLUDE THIS FIRST!
#include <Adafruit_ST7735.h>     // Hardware-specific library
#include <SPI.h>
#include <lvgl.h>
#include <ui/display_driver.h>

struct apc::ui::display_driver::impl {
  impl(const display_config& config)
      : tft(config.cs, config.dc, config.mosi, config.sclk, config.rst) {

    Serial.println("Initializing graphics driver...");

    tft.initR(INITR_GREENTAB);
    tft.setRotation(1);
    tft.setTextColor(ST7735_WHITE);

    Serial.println("Initializing LVGL glue...");

    LvGLStatus status = glue.begin(&tft, (TouchScreen*)nullptr);

    if (status != LVGL_OK) {
      Serial.printf("LVGL Glue error %d\r\n", (int)status);
    }

    lvgl_setup();
  }

  Adafruit_ST7735 tft;
  Adafruit_LvGL_Glue glue;

  void lvgl_setup(void) {
    // Create simple label centered on screen
    lv_obj_t* label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello Arduino BASTARDO!");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
  }
};

apc::ui::display_driver::display_driver(const display_config& config) {
  _impl = std::make_unique<impl>(config);
}

apc::ui::display_driver::~display_driver() = default;

void apc::ui::display_driver::update() {
  lv_task_handler();
  delay(5);
}