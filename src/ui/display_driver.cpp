#include <Adafruit_GFX.h>        // Core graphics library
#include <Adafruit_LvGL_Glue.h>  // Glue library header INCLUDE THIS FIRST!
#include <Adafruit_ST7735.h>     // Hardware-specific library
#include <FS.h>
#include <SPI.h>
#include <lvgl.h>
#include <ui/display_driver.h>
#include <ui/export/ui.h>

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
      Serial.printf("LVGL Glue error: %d\r\n", (int)status);
    }

    Serial.println("Bootstrapping UI screens...");
    ui_init();
  }

  Adafruit_ST7735 tft;
  Adafruit_LvGL_Glue glue;
  screen* activeScreen;
};

apc::ui::display_driver::display_driver(const display_config& config) {
  _impl = std::make_unique<impl>(config);
}

apc::ui::display_driver::~display_driver() = default;

void apc::ui::display_driver::update() {
  if (_impl->activeScreen != nullptr) {
    _impl->activeScreen->update();
  }

  lv_task_handler();
  delay(5);
}

apc::ui::screen* apc::ui::display_driver::active_screen() {
  return _impl->activeScreen;
}

void apc::ui::display_driver::set_screen(screen* screen) {
  lv_disp_load_scr(screen->get_object());
  _impl->activeScreen = screen;
}
