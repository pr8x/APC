#pragma once
#include <Audio.h>
#include <FS.h>
#include <audio/track.h>
#include <lvgl.h>
#include <ui/waveform_canvas.h>
#include <usb_drive.h>
#include <play_sd_mp3.h>

namespace apc {
namespace audio {

class deck {
 public:
  deck(
      AudioPlaySdMp3* stream,
      AudioAmplifier* ampL,
      AudioAmplifier* ampR,
      usb_drive* usb,
      lv_obj_t* trackLabel,
      lv_obj_t* artistLabel,
      lv_obj_t* bpmLabel,
      lv_obj_t* totalTimeLabel,
      lv_obj_t* remainingTimeLabel,
      lv_obj_t* keyLabel,
      lv_obj_t* waveformContainer);

  void play();

  void stop();

  bool is_playing();

  void update();

  void load_track(const track* track);

  void set_volume(float v);

 private:
  const track* _track;

  usb_drive* _usb;
  AudioPlaySdMp3* _stream;
  AudioAmplifier* _ampL;
  AudioAmplifier* _ampR;

  lv_obj_t* _trackLabel;
  lv_obj_t* _artistLabel;
  lv_obj_t* _bpmLabel;
  lv_obj_t* _totalTimeLabel;
  lv_obj_t* _remainingTimeLabel;
  lv_obj_t* _keyLabel;
  std::optional<audio::waveform> _waveform;
  ui::waveform_canvas _waveformCanvas;
};
}  // namespace audio
}  // namespace apc