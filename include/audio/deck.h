#pragma once
#include <audio/usb_audio_stream.h>
#include <Audio.h>
#include <FS.h>

namespace apc {
namespace audio {

class deck {
 public:
  deck(usb_audio_stream* stream, AudioAmplifier* ampL, AudioAmplifier* ampR)
      : _stream(stream), _ampL(ampL), _ampR(ampR) {}

  void play() {}

  void stop() { _stream->stop(); }

  bool is_playing() { return _stream->state() == playback_state::playing; }

  void load_track(File& track) {
    _track = track;
    _stream->play(_track);
  }

  void set_volume(float v) {
    _ampL->gain(v);
    _ampR->gain(v);
  }

 private:
  File _track;
  usb_audio_stream* _stream;
  AudioAmplifier* _ampL;
  AudioAmplifier* _ampR;
};
}  // namespace audio
}  // namespace apc