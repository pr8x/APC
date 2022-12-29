#pragma once
#include <ui/export/ui.h>
#include <ui/screen.h>

namespace apc {
namespace ui {
namespace screens {

class mixer_screen : public screen {
 public:
  mixer_screen() : screen(ui_MixerScreen) {}

  const char* name() override { return "mixer screen"; }
};

}  // namespace screens
}  // namespace ui
}  // namespace apc