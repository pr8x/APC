#pragma once
#include <Audio.h>
#include <TimeLib.h>
#include <stdio.h>
#include <ui/export/ui.h>
#include <ui/screen.h>
#include <usb_drive.h>

namespace apc {
namespace ui {
namespace screens {

class diag_screen : public screen {
 public:
  diag_screen(usb_drive* usb);

  void update() override;

  const char* name() override;

 private:
  usb_drive* _usb;
  time_t _appStartTime;
};

}  // namespace screens
}  // namespace ui
}  // namespace apc