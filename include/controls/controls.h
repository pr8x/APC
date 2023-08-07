#pragma once
#include <Encoder.h>
#include <stdint.h>

namespace apc {

class controls {
 public:
  Encoder browse_knob{32, 31};
};

}  // namespace apc