#pragma once
#include <FS.h>
#include <debug.h>
#include <play_sd_mp3.h>
#include <gsl/span>
#include <vector>

namespace apc {
namespace audio {

class waveform {
 public:
  static waveform generate(const File& file) {

    // waveform wf;

    // while (f.available()) {


    //     int16_t lsum = 0, rsum = 0;

    //     for (size_t i = 0; i < samplesRead; i++) {
    //       lsum += pcm[i];
    //       rsum += pcm[samplesRead + i];
    //     }

    //     frame f;
    //     f.lh = lsum / (float)samplesRead / UINT16_MAX;
    //     f.rh = rsum / (float)samplesRead / UINT16_MAX;
    //     APC_TRACE(wf._frames.push_back(f));
    //   }
    // }
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