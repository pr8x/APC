#pragma once
#include <AudioStream.h>
#include <play_memory.h>

namespace apc {
namespace audio {

class deck {
 public:
  deck(AudioPlayMemory* stream, AudioAmplifier* ampL, AudioAmplifier* ampR)
      : _stream(stream), _ampL(ampL), _ampR(ampR) {}

  void play() {}

  void stop() { _stream->stop(); }

  bool is_playing() { return _stream->isPlaying(); }

  void load_track(const unsigned int* data) { _stream->play(data); }

  void set_volume(float v) {
    _ampL->gain(v);
    _ampR->gain(v);
  }

 private:
  AudioPlayMemory* _stream;
  AudioAmplifier* _ampL;
  AudioAmplifier* _ampR;
};
}  // namespace audio
}  // namespace apc