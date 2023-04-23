#include <logger.h>
#include <ui/screens/mixer_screen.h>

apc::ui::screens::mixer_screen::mixer_screen(
    audio::audio_graph* audioGraph,
    display_driver* display,
    usb_drive* usb,
    browse_screen* browseScreen,
    controls* controls)
    : screen(ui_MixerScreen),
      _audioGraph(audioGraph),
      _display(display),
      _usb(usb),
      _browseScreen(browseScreen),
      _controls(controls),
      _deckA(
          &_audioGraph->Deck_A,
          &_audioGraph->Amp_AL,
          &_audioGraph->Amp_AR,
          _usb,
          ui_MixerScreen_DeckA_TrackLabel,
          ui_MixerScreen_DeckA_ArtistLabel,
          ui_MixerScreen_DeckA_BPMLabel,
          ui_MixerScreen_DeckA_TotalTimeLabel,
          ui_MixerScreen_DeckA_RemaiTimeLabel,
          ui_MixerScreen_DeckA_KeyLabel,
          ui_MixerScreen_DeckA_Waveform,
          ui_MixerScreen_DeckA_WaveformLabel),
      _deckB(
          &_audioGraph->Deck_B,
          &_audioGraph->Amp_BL,
          &_audioGraph->Amp_BR,
          _usb,
          ui_MixerScreen_DeckB_TrackLabel,
          ui_MixerScreen_DeckB_ArtistLabel,
          ui_MixerScreen_DeckB_BPMLabel,
          ui_MixerScreen_DeckB_TotalTimeLabel,
          ui_MixerScreen_DeckB_RemaiTimeLabel,
          ui_MixerScreen_DeckB_KeyLabel,
          ui_MixerScreen_DeckB_Waveform,
          ui_MixerScreen_DeckB_WaveformLabel) {
  _deckA.set_volume(1.0f);
  _deckB.set_volume(1.0f);

  constexpr double allpass[] = {1.0, 0.0, 0.0, 0.0, 0.0};
  _audioGraph->Filter_AL.setCoefficients(0, allpass);
  _audioGraph->Filter_AR.setCoefficients(0, allpass);
  _audioGraph->Filter_BL.setCoefficients(0, allpass);
  _audioGraph->Filter_BR.setCoefficients(0, allpass);

  // TODO: Prevent clipping
  _audioGraph->Mixer_Master_L.gain(DeckAMixerChannel, 0.5);
  _audioGraph->Mixer_Master_L.gain(DeckBMixerChannel, 0.5);

  _audioGraph->Mixer_Master_R.gain(DeckAMixerChannel, 0.5);
  _audioGraph->Mixer_Master_R.gain(DeckBMixerChannel, 0.5);
}

void apc::ui::screens::mixer_screen::set_master_volume(float vol) {
  _audioGraph->Amp_Master_L.gain(vol);
  _audioGraph->Amp_Master_R.gain(vol);
}

void apc::ui::screens::mixer_screen::set_headphones_volume(float vol) {
  _audioGraph->Amp_Headphone_L.gain(vol);
  _audioGraph->Amp_Headphone_R.gain(vol);
}

void apc::ui::screens::mixer_screen::load() {
  screen::load();

  _browseScreen->set_browse_callback(
      [this](const audio::track& track) { on_browse_selection(track); });
}

void apc::ui::screens::mixer_screen::update() {
  screen::update();

  _deckA.update();
  _deckB.update();

  if (_display->active_screen() != _browseScreen &&
      _controls->browse_knob.delta() != 0) {
    _display->open_screen(_browseScreen);
  }
}

const char* apc::ui::screens::mixer_screen::name() { return "mixer screen"; }

void apc::ui::screens::mixer_screen::on_browse_selection(
    const audio::track& track) {
  APC_LOG_DEBUG("Loading track on deck A: %s", track.file_name());
  _deckA.load_track(&track);
  _deckA.play();
}
