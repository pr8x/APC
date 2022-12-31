#pragma once
#include <controls/mux.h>

namespace apc {
class button {
 public:
  button(mux_pin pin) : _pin(pin) {}

  bool is_up() { return check(false); }
  bool is_down() { return check(true); }

 private:
  bool check(bool downOrUp) {
    bool isPressed = _pin.readDigital() == LOW;

    if (isPressed && !_pressed) {
      _pressed = true;
      return downOrUp;
    } else if (!isPressed && _pressed) {
      _pressed = false;
      return !downOrUp;
    }

    return false;
  }

  bool _pressed;
  mux_pin _pin;
};

}  // namespace apc
