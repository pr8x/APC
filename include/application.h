#include <ui/display_driver.h>
#include <usb_drive.h>

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
};
}  // namespace apc