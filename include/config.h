#pragma once
#include <ui/display_driver.h>
#include <controls/mux.h>

namespace apc {

static constexpr apc::ui::display_config DisplayConfig{10, 9, 11, 14, 8};

static constexpr apc::mux_config ControlsMux1Config{ 15, 0, 1, 2, 3 };

}