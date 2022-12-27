#pragma once
#include <ui/export/ui.h>
#include <ui/screen.h>

namespace apc {
namespace ui {
namespace screens {

class browse_screen : public screen {
 public:
  browse_screen() : screen(ui_BrowseScreen) {}
};

}  // namespace screens
}  // namespace ui
}  // namespace apc