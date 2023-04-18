#include <audio/deck.h>
#include <audio/waveform.h>
#include <logger.h>
#include <play_sd_mp3.h>
#include <stdlib.h>

apc::audio::deck::deck(
    AudioPlaySdMp3* stream,
    AudioAmplifier* ampL,
    AudioAmplifier* ampR,
    usb_drive* usb,
    lv_obj_t* trackLabel,
    lv_obj_t* artistLabel,
    lv_obj_t* bpmLabel,
    lv_obj_t* waveformContainer)
    : _track(nullptr),
      _stream(stream),
      _usb(usb),
      _ampL(ampL),
      _ampR(ampR),
      _trackLabel(trackLabel),
      _artistLabel(artistLabel),
      _bpmLabel(bpmLabel),
      _waveformCanvas(waveformContainer) {}

void apc::audio::deck::play() {
  if (_track != nullptr) {
    APC_LOG_DEBUG("Playing %s", _track->full_path());
    auto err = _stream->play(_usb->filesystem(), _track->full_path());

    if (err != ERR_CODEC_NONE) {
      APC_LOG_ERROR("Error: %d", err);
    }
  }
}

void apc::audio::deck::stop() { _stream->pause(true); }

bool apc::audio::deck::is_playing() { return _stream->isPlaying(); }

void apc::audio::deck::update() { _waveformCanvas.update(); }

void apc::audio::deck::load_track(const track* track) {
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

}

void apc::audio::deck::set_volume(float v) {
  _ampL->gain(v);
  _ampR->gain(v);
}
