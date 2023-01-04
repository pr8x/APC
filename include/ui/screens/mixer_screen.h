#pragma once
#include <audio/audio_graph.h>
#include <ui/export/ui.h>
#include <ui/screen.h>

namespace apc {
namespace ui {
namespace screens {

class mixer_screen : public screen {
 public:
  mixer_screen(audio::audio_graph* audioGraph, display_driver* display,
               browse_screen* browseScreen, controls* controls)
      : screen(ui_MixerScreen),
        _audioGraph(audioGraph),
        _display(display),
        _browseScreen(browseScreen),
        _controls(controls),
        _deckA(&_audioGraph->Deck_A, &_audioGraph->Amp_AL,
               &_audioGraph->Amp_AR),
        _deckB(&_audioGraph->Deck_B, &_audioGraph->Amp_BL,
               &_audioGraph->Amp_BR) {}

  void load() override {
    screen::load();

    _browseScreen->set_browse_callback(
        [this](File file) { on_browse_selection(file); });

    // TODO: Prevent clipping
    _audioGraph->Mixer_Master_L.gain(DeckAMixerChannel, 0.5);
    _audioGraph->Mixer_Master_L.gain(DeckBMixerChannel, 0.5);

    _audioGraph->Mixer_Master_R.gain(DeckAMixerChannel, 0.5);
    _audioGraph->Mixer_Master_R.gain(DeckBMixerChannel, 0.5);

    // _audioGraph.Filter_AL.setLowpass(0, 800, 0.707);
    // _audioGraph.Filter_AR.setLowpass(0, 800, 0.707);

    _deckA.set_volume(1.0f);
  }

  void update() override {
    screen::update();

    if (_display->active_screen() != _browseScreen &&
        _controls->browse_knob.delta() != 0) {
      _display->open_screen(_browseScreen);
    }
  }

  const char* name() override { return "mixer screen"; }

 private:
  void on_browse_selection(File file) {
    Serial.printf("Loading file on deck A: %s\n", file.name());
    _deckA.load_track(file);
  }

  static constexpr uint32_t DeckAMixerChannel = 0;
  static constexpr uint32_t DeckBMixerChannel = 1;

  audio::audio_graph* _audioGraph;
  display_driver* _display;
  browse_screen* _browseScreen;
  controls* _controls;

  apc::audio::deck _deckA;
  apc::audio::deck _deckB;
};

}  // namespace screens
}  // namespace ui
}  // namespace apc