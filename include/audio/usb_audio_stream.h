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
  usb_audio_stream() : AudioStream(0, nullptr) { AudioStartUsingSPI(); }

  void pause() {}

  void stop() {
    AudioStopUsingSPI();

    _state = playback_state::stopped;
    Serial.println("playback stopped");
  }

  playback_state state() { return _state; }

  void play(File file) {
    AudioStartUsingSPI();

    _file = std::move(file);
    _decoder = std::make_unique<mp3_decoder>(file, SampleBlockSize);
    _state = playback_state::playing;
    Serial.println("playback started");
  }

  void update() override {
    if (_state != playback_state::playing) {
      return;
    }

    auto block = _decoder->read_next_block();
    auto blockSize = block.leftChannel.size();
    auto isStereo = !block.rightChannel.empty();

    Serial.printf(
        "decoded block received: %d stereo: %d\n", blockSize, isStereo);

    // TODO: Do not dicard last incomplete frame
    if (blockSize < SampleBlockSize) {
      Serial.printf("decoded block too small");
      stop();
      return;
    }

    assert(blockSize == SampleBlockSize);

    audio_block_t* lb = allocate();
    assert(lb != nullptr);
    memcpy(lb->data, block.leftChannel.data(), block.leftChannel.size_bytes());
    transmit(lb, 0);
    release(lb);

    if (isStereo) {
      audio_block_t* rb = allocate();
      assert(rb != nullptr);
      memcpy(
          rb->data, block.rightChannel.data(), block.rightChannel.size_bytes());
      transmit(rb, 1);
      release(rb);
    }
  }

 private:
  static constexpr size_t SampleBlockSize = AUDIO_BLOCK_SAMPLES;

  std::unique_ptr<mp3_decoder> _decoder;
  File _file;
  playback_state _state = playback_state::stopped;
};

}  // namespace audio
}  // namespace apc
