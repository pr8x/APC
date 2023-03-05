#pragma once
#include <FS.h>
#include <debug.h>
#include <minimp3.h>

#include <gsl/span>
#include <vector>

namespace apc {
namespace audio {

class waveform {
 public:
  static waveform generate(const File& file) {
    std::vector<char> buffer(1638 * 10);

    waveform wf;

    static mp3dec_t mp3d;
    mp3dec_init(&mp3d);

    // TODO: const correctness in FS library
    auto& f = const_cast<File&>(file);

    int16_t pcm[MINIMP3_MAX_SAMPLES_PER_FRAME];
    mp3dec_frame_info_t info;

    while (f.available()) {
      auto bytesRead = APC_TRACE(f.readBytes(buffer.data(), buffer.size()));

      size_t offset = 0;

      while (offset < bytesRead) {
        auto samplesRead = APC_TRACE(mp3dec_decode_frame(
            &mp3d,
            (uint8_t*)buffer.data() + offset,
            bytesRead - offset,
            pcm,
            &info));

        offset += info.frame_bytes;

        if (samplesRead == 0) {
          if (info.frame_bytes > 0) {
            continue;
          } else {
            break;
          }
        }

        int16_t lsum = 0, rsum = 0;

        for (size_t i = 0; i < samplesRead; i++) {
          lsum += pcm[i];
          rsum += pcm[samplesRead + i];
        }

        frame f;
        f.lh = lsum / (float)samplesRead / UINT16_MAX;
        f.rh = rsum / (float)samplesRead / UINT16_MAX;
        APC_TRACE(wf._frames.push_back(f));
      }
    }
  }

  struct frame {
    uint8_t r = 0, g = 0, b = 0;
    float lh, rh;
  };

  gsl::span<const frame> frames() const { return _frames; }

 private:
  std::vector<frame> _frames;
};
}  // namespace audio
}  // namespace apc