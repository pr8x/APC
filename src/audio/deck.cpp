#include <audio/deck.h>
#include <audio/waveform.h>
#include <stdlib.h>

apc::audio::deck::deck(
    usb_audio_stream* stream,
    AudioAmplifier* ampL,
    AudioAmplifier* ampR,
    lv_obj_t* trackLabel,
    lv_obj_t* artistLabel,
    lv_obj_t* bpmLabel,
    lv_obj_t* waveformContainer)
    : _track(nullptr),
      _stream(stream),
      _ampL(ampL),
      _ampR(ampR),
      _trackLabel(trackLabel),
      _artistLabel(artistLabel),
      _bpmLabel(bpmLabel),
      _waveformCanvas(waveformContainer) {}

void apc::audio::deck::play() {
  if (_track != nullptr) {
    _stream->play(_track->file());
  }
}

void apc::audio::deck::stop() { _stream->stop(); }

bool apc::audio::deck::is_playing() {
  return _stream->state() == playback_state::playing;
}

void apc::audio::deck::update() { _waveformCanvas.update(); }

void apc::audio::deck::load_track(const track* track) {
  stop();

  _track = track;

  if (_track == nullptr) {
    return;
  }

  const auto meta = _track->metadata();

  if (meta) {
    lv_label_set_text(_trackLabel, meta->title.c_str());
    lv_label_set_text(_artistLabel, meta->artist.c_str());

    char b[8];
    itoa(meta->bpm, b, 10);
    lv_label_set_text(_bpmLabel, b);

  } else {
    lv_label_set_text(_trackLabel, track->file().name());
    lv_label_set_text(_artistLabel, "Unknown");
    lv_label_set_text(_bpmLabel, "N/A");
  }

  _waveform = APC_TRACE(audio::waveform::generate(_track->file()));

  APC_TRACE(_waveformCanvas.set_waveform(&*_waveform));
}

void apc::audio::deck::set_volume(float v) {
  _ampL->gain(v);
  _ampR->gain(v);
}
