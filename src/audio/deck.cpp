#include <audio/deck.h>
#include <audio/waveform.h>
#include <logger.h>
#include <play_sd_mp3.h>
#include <stdlib.h>
#include <util.h>

apc::audio::deck::deck(
    AudioPlaySdMp3* stream,
    AudioAmplifier* ampL,
    AudioAmplifier* ampR,
    audio::equalizer eq,
    usb_drive* usb,
    lv_obj_t* trackLabel,
    lv_obj_t* artistLabel,
    lv_obj_t* bpmLabel,
    lv_obj_t* totalTimeLabel,
    lv_obj_t* remainingTimeLabel,
    lv_obj_t* keyLabel,
    lv_obj_t* waveformContainer,
    lv_obj_t* waveformLabel)
    : _track(nullptr),
      _stream(stream),
      _usb(usb),
      _ampL(ampL),
      _ampR(ampR),
      _eq(std::move(eq)),
      _trackLabel(trackLabel),
      _artistLabel(artistLabel),
      _bpmLabel(bpmLabel),
      _totalTimeLabel(totalTimeLabel),
      _remainingTimeLabel(remainingTimeLabel),
      _keyLabel(keyLabel),
      _waveformCanvas(waveformContainer),
      _waveformLabel(waveformLabel) {
  lv_obj_add_flag(_waveformLabel, LV_OBJ_FLAG_HIDDEN);
}

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

void apc::audio::deck::update() {
  if (is_playing()) {
    auto currentPos = _stream->positionMillis();

    fixed_string_builder<24> sb;

    sb.append_time(currentPos);
    lv_label_set_text(_remainingTimeLabel, sb.str());

    _waveformCanvas.set_offset(currentPos);
    _waveformCanvas.update();
  }
}

void apc::audio::deck::load_track(const track* track) {
  _track = track;

  if (_track == nullptr) {
    return;
  }

  const auto meta = _track->metadata();

  if (meta && !meta->artist.empty()) {
    lv_label_set_text(_artistLabel, meta->artist.c_str());
  } else {
    lv_label_set_text(_artistLabel, "Unknown");
  }

  if (meta && !meta->title.empty()) {
    lv_label_set_text(_trackLabel, meta->title.c_str());
  } else {
    lv_label_set_text(_trackLabel, track->file_name());
  }

  if (meta && !meta->key.empty()) {
    lv_label_set_text(_keyLabel, meta->key.c_str());
  } else {
    lv_label_set_text(_keyLabel, "N/A");
  }

  if (meta && meta->bpm) {
    char b[8];
    itoa(*meta->bpm, b, 10);
    lv_label_set_text(_bpmLabel, b);
  } else {
    lv_label_set_text(_keyLabel, "N/A");
  }

  if (meta && meta->lengthMillis) {
    fixed_string_builder<24> sb;
    sb.append_time(*meta->lengthMillis);
    lv_label_set_text(_totalTimeLabel, sb.str());
  } else {
    lv_label_set_text(_totalTimeLabel, "N/A");
  }

  // APC_LOG_DEBUG("Generating waveform...");
  // lv_obj_clear_flag(_waveformLabel, LV_OBJ_FLAG_HIDDEN);

  // _waveform = waveform::generate(
  //     _track->file(),
  //     [this](float progress) {
  //       fixed_string_builder<24> sb;
  //       sb.append_format("Loading...%d%%", (int)(progress * 100));

  //       lv_label_set_text(_waveformLabel, sb.str());
  //       lv_task_handler();
  //     },
  //     waveform_type::rms);

  // lv_obj_add_flag(_waveformLabel, LV_OBJ_FLAG_HIDDEN);

  // APC_LOG_DEBUG(
  //     "Waveform generated with %d frames", _waveform->frames().size());

  // _waveformCanvas.set_waveform(&*_waveform);
}

void apc::audio::deck::set_volume(float v) {
  _ampL->gain(v);
  _ampR->gain(v);
}

apc::audio::equalizer& apc::audio::deck::eq() { return _eq; }
