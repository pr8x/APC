#pragma once
#include <Audio.h>
#include <FS.h>
#include <audio/equalizer.h>
#include <audio/track.h>
#include <filter_biquad.h>
#include <lvgl.h>
#include <play_sd_mp3.h>
#include <ui/waveform_canvas.h>
#include <usb_drive.h>

namespace apc {
namespace audio {

class deck {
 public:
  deck(
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
      lv_obj_t* waveformLabel);

  /// @brief
  void play();

  /// @brief
  void stop();

  /// @brief
  /// @return
  bool is_playing();

  /// @brief
  void update();

  /// @brief
  /// @param track
  void load_track(const track* track);

  /// @brief
  /// @param v
  void set_volume(float v);

  /// @brief
  /// @return
  equalizer& eq();

 private:
  const track* _track;

  usb_drive* _usb;
  AudioPlaySdMp3* _stream;
  AudioAmplifier* _ampL;
  AudioAmplifier* _ampR;
  audio::equalizer _eq;

  lv_obj_t* _trackLabel;
  lv_obj_t* _artistLabel;
  lv_obj_t* _bpmLabel;
  lv_obj_t* _totalTimeLabel;
  lv_obj_t* _remainingTimeLabel;
  lv_obj_t* _keyLabel;
  lv_obj_t* _waveformLabel;

  std::optional<audio::waveform> _waveform;
  ui::waveform_canvas _waveformCanvas;
};
}  // namespace audio
}  // namespace apc