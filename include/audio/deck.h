#pragma once
#include <Audio.h>
#include <FS.h>
#include <audio/track.h>
#include <audio/usb_audio_stream.h>
#include <lvgl.h>
#include <ui/waveform_canvas.h>
#include <usb_drive.h>

namespace apc {
namespace audio {

class deck {
 public:
  deck(
      AudioStream* stream,
      AudioAmplifier* ampL,
      AudioAmplifier* ampR,
      usb_drive* usb,
      lv_obj_t* trackLabel,
      lv_obj_t* artistLabel,
      lv_obj_t* bpmLabel,
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
  AudioStream* _stream;
  AudioAmplifier* _ampL;
  AudioAmplifier* _ampR;

  lv_obj_t* _trackLabel;
  lv_obj_t* _artistLabel;
  lv_obj_t* _bpmLabel;
  std::optional<audio::waveform> _waveform;
  ui::waveform_canvas _waveformCanvas;
};
}  // namespace audio
}  // namespace apc