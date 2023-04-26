#pragma once
#include <controls/mux.h>
#include <util.h>

namespace apc {
class potentiometer {
 public:
  potentiometer(mux_pin pin) : _pin(pin) {}

  float value() { return value(0, 1); }

  float value(float min, float max) {
    return util::map(_pin.readAnalog() / 1024.0f, 0.0f, 1.0f, min, max);
  }

 private:
  mux_pin _pin;
};

}  // namespace apc
