#pragma once
#include <memory>
#include <FS.h>

namespace apc {

class usb_drive {
 public:
  usb_drive();
  ~usb_drive();

  const char* product_name();

  bool is_connected();

  File openPath(const char* path);

  void update();

 private:
  struct impl;
  std::unique_ptr<impl> _impl;
};

}  // namespace apc