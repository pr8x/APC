#pragma once
#include <Arduino.h>
#include <CD74HC4067.h>

namespace apc {

struct mux_config {
  int sig;
  int c1;
  int c2;
  int c3;
  int c4;
};

struct mux_pin {
 public:
  mux_pin(int pin, int muxSig, CD74HC4067* mux)
      : _pin(pin), _muxSig(muxSig), _mux(mux) {}

  int readAnalog() {
    select_channnel();
    return analogRead(_muxSig);
  }

  uint8_t readDigital() {
    select_channnel();
    return digitalRead(_muxSig);
  }

 private:
  void select_channnel() {
    _mux->channel(_pin);

    // https://forum.pjrc.com/threads/57248-Teensy-3-6-Problem-with-Mux-(CD74HC4067)-and-Reading-Buttons
    delayMicroseconds(5);
  }

  int _pin;
  int _muxSig;
  CD74HC4067* _mux;
};

}  // namespace apc