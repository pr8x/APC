#pragma once
#include <Arduino.h>
#include <logger.h>

#define APC_ENABLE_GDB_STUB 0

#if APC_ENABLE_GDB_STUB
#include "TeensyDebug.h"
#define APC_BREAKPOINT halt_cpu()
#else
#define APC_BREAKPOINT
#endif

#define APC_DEBUG 1
#define APC_DEBUG_TRACE 1

namespace apc {

namespace detail {

template <class T>
decltype(auto) trace(T&& ret, const char* callExpr) {
  APC_LOG_TRACE("%s", callExpr);
  return ret();
}

}  // namespace detail

#if APC_DEBUG_TRACE
#define APC_TRACE(f) detail::trace([&]() { return f; }, #f)
#else
#define APC_TRACE(f) f
#endif

}  // namespace apc