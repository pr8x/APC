#include <Arduino.h>
#include <TimeLib.h>
#include <application.h>

namespace {
constexpr apc::ui::display_config DefaultDisplayConfig{10, 9, 11, 14, 8};

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
  // set the Time library to use Teensy 3.0's RTC to keep time
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
      _display(DefaultDisplayConfig),
      _browseScreen(&_controls, &_usb) {

  _display.set_screen(&_browseScreen);
}

void apc::application::update() {
  _usb.update();
  _display.update();
}
