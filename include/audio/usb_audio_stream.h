#pragma once
#include <Arduino.h>
#include <AudioStream.h>
#include <FS.h>
#include <audio/mp3_decoder.h>
#include <circular_queue.h>
#include <spi_interrupt.h>

namespace apc {
namespace audio {

enum class playback_state { playing, paused, stopped };

class usb_audio_stream : public AudioStream {
 public:
  usb_audio_stream() : AudioStream(1, nullptr) { AudioStartUsingSPI(); }

  void pause() {}

  void stop() {
    _state = playback_state::stopped;
    Serial.println("playback stopped");
  }

  playback_state state() { return _state; }

  void play(File file) {
    _file = std::move(file);
    _decoder = std::make_unique<mp3_decoder<SampleBlockSize>>(file);
    _state = playback_state::playing;
     Serial.println("playback started");
  }

  void update() override {
    if (_state != playback_state::playing) {
      return;
    }

    audio_block_t* lb = allocate();
    audio_block_t* rb = allocate();
    assert(lb != nullptr && rb != nullptr);

    gsl::span<int16_t> block = _decoder->read_next_block();

    Serial.printf("decoded block received: %d\n", block.size());

    // TODO: Do not dicard last incomplete frame
    if (block.size() < SampleBlockSize) {
      Serial.printf("decoded block too small");
      stop();
      return;
    }

    for (size_t i = 0; i < SampleBlockSize / 2; i++) {
      lb->data[i] = block[i * 2];
      rb->data[i] = block[i * 2 + 1];
    }

    release(lb);
    release(rb);
  }

 private:
  static constexpr size_t SampleBlockSize = AUDIO_BLOCK_SAMPLES * 2;

  std::unique_ptr<mp3_decoder<SampleBlockSize>> _decoder;
  File _file;
  playback_state _state = playback_state::stopped;
};

}  // namespace audio
}  // namespace apc
