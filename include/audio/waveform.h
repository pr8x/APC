#pragma once
#include <FS.h>
#include <gsl/span>
#include <tl/function_ref.hpp>
#include <vector>

#define APC_WAVEFORM_FFT_SUPPORT 1

namespace apc {
namespace audio {

class waveform {
 public:
  struct frame {
    uint8_t r = 0, g = 0, b = 0;
    int16_t min = 0, max = 0;
  };

  static waveform generate(
      File file, tl::function_ref<void(float progress)> progressCallback);

  gsl::span<const frame> frames() const { return _frames; }

 private:
  std::vector<frame> _frames;
};
}  // namespace audio
}  // namespace apc