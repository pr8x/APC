#pragma once
#include <algorithm>

namespace apc {

template <class T>
T clamp(T v, T min, T max) {
  return std::max(min, std::min(v, max));
}

template <size_t Size>
class fixed_string_builder {
 public:
  template <class... TArgs>
  void append_format(const char* format, const TArgs&... args) {
    _offset += sprintf(_offset, format, args...);
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