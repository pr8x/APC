#pragma once
#include <FS.h>

#include <gsl/span>
#include <tl/function_ref.hpp>
#include <vector>

#define APC_WAVEFORM_FFT_SUPPORT 0

namespace apc {
namespace audio {

enum class waveform_type { peak, mean, rms };

class waveform {
 public:
  struct frame {
    uint8_t r = 0, g = 0, b = 0;
    int16_t v = 0;
  };

  static waveform generate(
      File file,
      tl::function_ref<void(float progress)> progressCallback,
      waveform_type type);

  gsl::span<const frame> frames() const;

  uint64_t frame_length();

 private:
  uint64_t _frameLengthMillis;
  std::vector<frame> _frames;
};
}  // namespace audio
}  // namespace apc