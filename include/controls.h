#include <CD74HC4067.h>
#include <stdint.h>

namespace apc {

struct control_pin {
 public:
  control_pin(int pin, int muxSig, CD74HC4067* mux)
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

class rotary_switch {
 public:
  rotary_switch(control_pin s1, control_pin s2, control_pin key)
      : _s1(s1), _s2(s2), _key(key) {
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

    //delay(1);
    return dir;
  }

  bool button() { return _key.readDigital() == LOW; }

 private:
  control_pin _s1;
  control_pin _s2;
  control_pin _key;
  int _state;
};

class potentiometer {
 public:
  potentiometer(control_pin pin) : _pin(pin) {}

  float read() { return _pin.readAnalog() / 1024.0f; }

 private:
  control_pin _pin;
};

class controls {
 public:
  controls() : _mux1Sig(23), _mux1(0, 1, 2, 3) { pinMode(_mux1Sig, INPUT); }

 private:
  int _mux1Sig;
  CD74HC4067 _mux1;

  control_pin mux1_pin(int pin) { return {pin, _mux1Sig, &_mux1}; }

 public:
  potentiometer master_volume_pot{mux1_pin(15)};

  rotary_switch browse_knob{mux1_pin(1), mux1_pin(2), mux1_pin(0)};
};

}  // namespace apc