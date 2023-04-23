#pragma once
#include <ui/display_driver.h>
#include <controls/mux.h>
#include <log_severity.h>

namespace apc {

//TODO: Put into apc.config.json
static constexpr log_severity LogSeverity = log_severity::debug;

static constexpr uint32_t AudioMemoryBlocks = 10;

static constexpr apc::ui::display_config DisplayConfig{10, 9, 11, 14, 8};

static constexpr apc::mux_config ControlsMux1Config{ 15, 0, 1, 2, 3 };

}