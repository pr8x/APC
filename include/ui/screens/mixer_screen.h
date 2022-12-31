#pragma once
#include <ui/export/ui.h>
#include <ui/screen.h>

namespace apc {
namespace ui {
namespace screens {

class mixer_screen : public screen {
 public:
  mixer_screen(display_driver* display, browse_screen* browseScreen,
               controls* controls)
      : screen(ui_MixerScreen) {
    _display = display;
    _browseScreen = browseScreen;
    _controls = controls;
  }

  void update() override {
    if (_display->active_screen() != _browseScreen &&
        _controls->browse_knob.delta() != 0) {
      _display->open_screen(_browseScreen);
    }
  }

  const char* name() override { return "mixer screen"; }

 private:
  display_driver* _display;
  browse_screen* _browseScreen;
  controls* _controls;
};

}  // namespace screens
}  // namespace ui
}  // namespace apc