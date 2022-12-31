#pragma once
#include <controls/mux.h>

namespace apc {
class potentiometer {
 public:
  potentiometer(mux_pin pin) : _pin(pin) {}

  float value() { return _pin.readAnalog() / 1024.0f; }

 private:
  mux_pin _pin;
};

}  // namespace apc
