#pragma once
#include <dspinst.h>

#include <algorithm>
#include <gsl/span>

namespace apc {

namespace util {

template <class T>
T clamp(T v, T min, T max) {
  return std::max(min, std::min(v, max));
}

template <class T>
T map(T in, T inMin, T inMax, T outMin, T outMax) {
  return (in - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}

}  // namespace util

template <size_t Size>
class fixed_string_builder {
 public:
  template <class... TArgs>
  void append_format(const char* format, const TArgs&... args) {
    _offset += sprintf(_offset, format, args...);
  }

  // TODO: Make <chrono> compile
  void append_time(uint32_t milli) {
    long hr = milli / 3600000;
    milli = milli - 3600000 * hr;
    long min = milli / 60000;
    milli = milli - 60000 * min;
    long sec = milli / 1000;
    milli = milli - 1000 * sec;

    append_format("%02ld:%02ld", min, sec);
  }

  const char* str() const {
    *(_offset + 1) = '\0';
    return _buffer;
  }

 private:
  char _buffer[Size + 1];
  char* _offset = _buffer;
};

}  // namespace apc