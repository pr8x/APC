#pragma once
#include <FS.h>
#include <vector>

namespace apc {
namespace audio {

class waveform {
 public:
  static waveform generate(File* file) {}

  struct frame {
    uint8_t r, g, b;
    uint8_t h;
  };

 private:
  std::vector<frame> _frames;
};
}  // namespace audio
}  // namespace apc