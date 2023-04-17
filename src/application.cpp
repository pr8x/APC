#include <Arduino.h>
#include <TimeLib.h>
#include <application.h>
#include <config.h>

apc::application::application()
    : _display(DisplayConfig),
      _controls(ControlsMux1Config),
      _diagScreen(&_usb),
      _mixerScreen(&_audioGraph, &_display, &_usb, &_browseScreen, &_controls),
      _browseScreen(&_controls, &_usb, &_trackDb) {
  _display.open_screen(&_mixerScreen);
}

void apc::application::update() {
  if (_controls.menu_button.is_down()) {
    if (_display.active_screen() == &_diagScreen) {
      _diagScreen.close();
    } else {
      _display.open_screen(&_diagScreen);
    }
  }

  _usb.update();
  _display.update();
}
