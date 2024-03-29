#pragma once
#include <ui/export/ui.h>
#include <ui/screen.h>

namespace apc {
namespace ui {
namespace screens {

class splash_screen : public screen {
 public:
  splash_screen() : screen(ui_SplashScreen) {}

  const char* name() override { return "splash screen"; }
};

}  // namespace screens
}  // namespace ui
}  // namespace apc