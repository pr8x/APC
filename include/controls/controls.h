#pragma once
#include <CD74HC4067.h>
#include <controls/button.h>
#include <controls/mux.h>
#include <controls/potentiometer.h>
#include <controls/rotary_switch.h>
#include <stdint.h>

namespace apc {

class controls {
 public:
  controls(const mux_config& mux1Config)
      : _mux1Sig(mux1Config.sig),
        _mux1(mux1Config.c1, mux1Config.c2, mux1Config.c3, mux1Config.c4) {
    pinMode(_mux1Sig, INPUT_PULLUP);
  }

 private:
  int _mux1Sig;
  CD74HC4067 _mux1;

  mux_pin mux1_pin(int pin) { return {pin, _mux1Sig, &_mux1}; }

 public:
  button menu_button{mux1_pin(3)};

  potentiometer master_volume_pot{mux1_pin(15)};

  rotary_switch browse_knob{mux1_pin(1), mux1_pin(2), mux1_pin(0)};
};

}  // namespace apc