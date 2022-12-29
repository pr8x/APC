#pragma once
#include <AudioStream.h>
#include <play_memory.h>

namespace apc {
namespace audio {
class deck {
 public:
  deck(AudioPlayMemory* stream) {}

  void play() {}

  void stop() { _stream->stop(); }

  bool is_playing() { return _stream->isPlaying(); }

  void load_track(const unsigned int* data) { _stream->play(data); }

 private:
  AudioPlayMemory* _stream;
};
}  // namespace audio
}  // namespace apc