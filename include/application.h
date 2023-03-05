#pragma once
#include <audio/audio_graph.h>
#include <audio/deck.h>
#include <audio/track_database.h>
#include <controls/controls.h>
#include <ui/display_driver.h>
#include <ui/screens/browse_screen.h>
#include <ui/screens/diag_screen.h>
#include <ui/screens/mixer_screen.h>
#include <ui/screens/splash_screen.h>
#include <usb_drive.h>

namespace apc {

class application {
 public:
  application();

  void update();

 private:
  usb_drive _usb;
  ui::display_driver _display;
  controls _controls;
  audio::audio_graph _audioGraph;
  audio::track_database _trackDb;

  ui::screens::diag_screen _diagScreen;
  ui::screens::mixer_screen _mixerScreen;
  ui::screens::splash_screen _splashScreen;
  ui::screens::browse_screen _browseScreen;
};
}  // namespace apc