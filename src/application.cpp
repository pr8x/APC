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
      // _deckA(&_audioGraph.Deck_A),
      // _deckB(&_audioGraph.Deck_B),
      _browseScreen(&_controls, &_usb) {
  _browseScreen.set_browse_callback(
      [this](const char* f) { on_browse_selection(f); });
  _display.push_screen(&_mixerScreen);
}

void apc::application::update() {
  if (_display.active_screen() != &_browseScreen &&
      _controls.browse_knob.delta() != 0) {
    _display.push_screen(&_browseScreen);
  }

  _usb.update();
  _display.update();
}

void apc::application::on_browse_selection(const char* file) {
  Serial.printf("on_browse_selection: %s\n", file);
}
