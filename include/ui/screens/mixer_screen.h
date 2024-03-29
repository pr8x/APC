#pragma once
#include <audio/audio_graph.h>
#include <audio/equalizer.h>
#include <audio/deck.h>
#include <audio/track.h>
#include <ui/export/ui.h>
#include <ui/screen.h>
#include <ui/screens/browse_screen.h>
#include <ui/waveform_canvas.h>

namespace apc {
namespace ui {
namespace screens {

class mixer_screen : public screen {
 public:
  mixer_screen(
      audio::audio_graph* audioGraph,
      display_driver* display,
      usb_drive* usb,
      browse_screen* browseScreen,
      controls* controls);

  void set_master_volume(float vol);

  void set_headphones_volume(float vol);

  void load() override;

  void update() override;

  const char* name() override;

 private:
  void on_browse_selection(const audio::track& track);

  void update_deck_eq();

  static constexpr uint32_t DeckAMixerChannel = 0;
  static constexpr uint32_t DeckBMixerChannel = 1;

  audio::audio_graph* _audioGraph;
  usb_drive* _usb;
  display_driver* _display;
  browse_screen* _browseScreen;
  controls* _controls;

  apc::audio::deck _deckA;
  apc::audio::deck _deckB;
};

}  // namespace screens
}  // namespace ui
}  // namespace apc