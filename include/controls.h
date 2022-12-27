#include <CD74HC4067.h>
#include <stdint.h>

namespace apc {

struct control_pin {
 public:
  control_pin(int pin, int muxSig, CD74HC4067* mux)
      : _pin(pin), _muxSig(muxSig), _mux(mux) {}

  int read(bool analog = true) {
    _mux->channel(_pin);

    if (analog) {
      return analogRead(_muxSig);
    }

    return digitalRead(_muxSig);
  }

 private:
  int _pin;
  int _muxSig;
  CD74HC4067* _mux;
};

class rotary_switch {
 public:
  rotary_switch(control_pin s1, control_pin s2, control_pin key)
      : _s1(s1), _s2(s2), _key(key) {
    _state1 = _s1.read(false);
  }

  int delta() { return _s1.read(false) + _s2.read(false); }

  bool button() { return _key.read(false) == HIGH; }

 private:
  control_pin _s1;
  control_pin _s2;
  control_pin _key;
  int _state1;
};

class potentiometer {
 public:
  potentiometer(control_pin pin) : _pin(pin) {}

  float read() { return _pin.read() / 1024.0f; }

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
  potentiometer master_volume_pot{mux1_pin(0)};

  rotary_switch browse_knob{mux1_pin(2), mux1_pin(3), mux1_pin(1)};
};

}  // namespace apc