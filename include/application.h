#pragma once
#include <audio/audio_graph.h>
#include <audio/deck.h>
#include <controls/controls.h>
#include <ui/display_driver.h>
#include <ui/screens/browse_screen.h>
#include <ui/screens/mixer_screen.h>
#include <ui/screens/splash_screen.h>
#include <ui/screens/diag_screen.h>
#include <usb_drive.h>

namespace apc {

class application {
 public:
  application();

  void update();

 private:
  apc::usb_drive _usb;
  apc::ui::display_driver _display;
  apc::controls _controls;
  apc::audio::audio_graph _audioGraph;

  apc::ui::screens::diag_screen _diagScreen;
  apc::ui::screens::mixer_screen _mixerScreen;
  apc::ui::screens::splash_screen _splashScreen;
  apc::ui::screens::browse_screen _browseScreen;
};
}  // namespace apc