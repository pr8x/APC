#pragma once
#include <ui/display_driver.h>
#include <usb_drive.h>
#include <ui/screens/browse_screen.h>
#include <ui/screens/splash_screen.h>
#include <controls.h>

#define APC_DEBUG 1

namespace apc {

class application {
 public:
  application();

  void update();

 private:
  bool _running;
  apc::usb_drive _usb;
  apc::ui::display_driver _display;
  apc::controls _controls;

  apc::ui::screens::splash_screen _splashScreen;
  apc::ui::screens::browse_screen _browseScreen;
};
}  // namespace apc