#pragma once
#include <Arduino.h>

#include "TeensyDebug.h"

#define APC_DEBUG 1
#define APC_DEBUG_TRACE 1

#define APC_ENABLE_GDB_STUB 1
#define APC_BREAKPOINT halt_cpu()

namespace apc {

namespace detail {

template <class T>
decltype(auto) trace(T&& ret, const char* callExpr) {
  Serial.println(callExpr);
  return ret();
}

}  // namespace detail

#if APC_DEBUG_TRACE
#define APC_TRACE(f) detail::trace([&]() { return f; }, #f)
#else
#define APC_TRACE(f) f
#endif

}  // namespace apc