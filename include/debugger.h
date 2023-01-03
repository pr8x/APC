#pragma once
#include <Arduino.h>
#include "TeensyDebug.h"

#define APC_BREAKPOINT halt_cpu()

namespace apc {

inline void init_debugger() { debug.begin(SerialUSB1); }

}  // namespace apc