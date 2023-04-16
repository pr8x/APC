#include <Adafruit_GFX.h>        // Core graphics library
#include <Adafruit_LvGL_Glue.h>  // Glue library header INCLUDE THIS FIRST!
#include <Adafruit_ST7789.h>     // Hardware-specific library
#include <FS.h>
#include <SPI.h>
#include <lvgl.h>
#include <ui/display_driver.h>
#include <ui/export/ui.h>
#include <logger.h>

#include <cassert>
#include <vector>

struct apc::ui::display_driver::impl {
  impl(const display_config& config)
      : tft(config.cs, config.dc, config.mosi, config.sclk, config.rst) {
    APC_LOG_INFO("Initializing graphics driver...");

    tft.init(240, 320); 
    tft.setRotation(3);
    tft.setTextColor(ST77XX_WHITE);
    tft.invertDisplay(false);

    APC_LOG_INFO("Initializing LVGL glue...");

    LvGLStatus status = glue.begin(&tft, (TouchScreen*)nullptr);

    if (status != LVGL_OK) {
      APC_LOG_ERROR("LVGL Glue error: %d", (int)status);
    }

    screenStack.reserve(5);

    APC_LOG_INFO("Bootstrapping UI screens...");
    ui_init();
  }

  Adafruit_ST7789 tft;
  Adafruit_LvGL_Glue glue;
  std::vector<screen*> screenStack;
};

apc::ui::display_driver::display_driver(const display_config& config) {
  _impl = std::make_unique<impl>(config);
}

apc::ui::display_driver::~display_driver() = default;

void apc::ui::display_driver::update() {
  auto activeScreen = active_screen();
  activeScreen->update();

  lv_task_handler();
  delay(5);
}

apc::ui::screen* apc::ui::display_driver::active_screen() {
  if (_impl->screenStack.empty()) {
    return nullptr;
  }
  return _impl->screenStack.back();
}

void apc::ui::display_driver::open_screen(screen* screen) {
  auto activeScreen = active_screen();

  if (activeScreen != nullptr) {
    activeScreen->set_close_callback(nullptr);
  }

  APC_LOG_DEBUG("Screen opened: %s -> %s",
                activeScreen != nullptr ? activeScreen->name() : "[NULL]",
                screen->name());

  lv_disp_load_scr(screen->get_object());
  _impl->screenStack.push_back(screen);

  screen->set_close_callback([this, screen]() {
    _impl->screenStack.pop_back();
    assert(!_impl->screenStack.empty());
    auto nextScreen = _impl->screenStack.back();

    APC_LOG_DEBUG("Screen closed: %s -> %s", screen->name(),
                  nextScreen->name());

    lv_disp_load_scr(nextScreen->get_object());
  });

  screen->load();
}
