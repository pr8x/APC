#pragma once
#include <controls/mux.h>
#include <controls/button.h>

namespace apc {

class rotary_switch {
 public:
  rotary_switch(mux_pin s1, mux_pin s2, mux_pin key)
      : button(key), _s1(s1), _s2(s2) {
    _state = _s1.readDigital();
  }

  int delta() {
    auto currentState = _s1.readDigital();
    auto dir = 0;

    if (currentState != _state && currentState == HIGH) {
      if (_s2.readDigital() != currentState) {
        dir = -1;
      } else {
        dir = 1;
      }
    }

    _state = currentState;

    // delay(1);
    return dir;
  }

  button button;

 private:
  mux_pin _s1;
  mux_pin _s2;
  int _state;
};

}  // namespace apc
