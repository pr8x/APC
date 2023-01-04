#pragma once
#include <AudioStream.h>
#include <play_memory.h>

namespace apc {
namespace audio {

class deck {
 public:
  deck(AudioPlayUSBWav* stream, AudioAmplifier* ampL, AudioAmplifier* ampR)
      : _stream(stream), _ampL(ampL), _ampR(ampR) {}

  void play() {}

  void stop() { _stream->stop(); }

  bool is_playing() { return _stream->isPlaying(); }

  void load_track(File& track) {
    _track = track;
    _stream->play(&_track);
  }

  void set_volume(float v) {
    _ampL->gain(v);
    _ampR->gain(v);
  }

 private:
  File _track;
  AudioPlayUSBWav* _stream;
  AudioAmplifier* _ampL;
  AudioAmplifier* _ampR;
};
}  // namespace audio
}  // namespace apc