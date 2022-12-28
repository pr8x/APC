#pragma once
#include <algorithm>

namespace apc {

template<class T>
T clamp(T v, T min, T max) {
  return std::max(min, std::min(v, max));
}
}  // namespace apc