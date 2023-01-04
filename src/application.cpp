#include <Arduino.h>
#include <TimeLib.h>
#include <application.h>
#include <config.h>

namespace {
void setup_serial() {
  Serial.begin(9600);

#if APC_DEBUG
  while (!Serial) {
    // wait for serial port to connect.
  }
#endif
}

time_t get_teensy_time() { return Teensy3Clock.get(); }

void sync_with_RTC() {
  // set the Time library to use Teensy RTC to keep time
  setSyncProvider(get_teensy_time);

  if (timeStatus() != timeSet) {
    Serial.println("Unable to sync with the RTC");
  } else {
    Serial.println("RTC has set the system time");
  }
}

}  // namespace

apc::application::application()
    : _running([]() {
        setup_serial();
        sync_with_RTC();

        return true;
      }()),
      _display(DisplayConfig),
      _controls(ControlsMux1Config),
      _diagScreen(&_usb),
      _mixerScreen(&_audioGraph, &_display, &_browseScreen, &_controls),
      _browseScreen(&_controls, &_usb) {
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
