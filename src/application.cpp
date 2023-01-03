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
      _deckA(&_audioGraph.Deck_A, &_audioGraph.Amp_AL, &_audioGraph.Amp_AR),
      _deckB(&_audioGraph.Deck_B, &_audioGraph.Amp_BL, &_audioGraph.Amp_BR),
      _diagScreen(&_usb),
      _mixerScreen(&_display, &_browseScreen, &_controls),
      _browseScreen(&_controls, &_usb) {
  _browseScreen.set_browse_callback(
      [this](File f) { on_browse_selection(f); });
  _display.open_screen(&_mixerScreen);

  AudioMemory(10);

  _audioGraph.Mixer_Master_L.gain(0, 0.5);
  _audioGraph.Mixer_Master_L.gain(1, 0.5);

  _audioGraph.Mixer_Master_R.gain(0, 0.5);
  _audioGraph.Mixer_Master_R.gain(1, 0.5);

  // _audioGraph.Filter_AL.setLowpass(0, 800, 0.707);
  // _audioGraph.Filter_AR.setLowpass(0, 800, 0.707);

  _deckA.set_volume(1.0f);
}

void apc::application::update() {
  // if (!_deckA.is_playing()) {
  //   _deckA.load_track(AudioSampleGong);
  // }

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

void apc::application::on_browse_selection(File file) {
  Serial.printf("on_browse_selection: %s\n", file.name());
}
