#pragma once
#include <FS.h>

#include <memory>

namespace apc {

class usb_drive {
 public:
  usb_drive();
  ~usb_drive();

  const char* product_name();

  bool is_connected();

  bool is_busy();

  File open_path(const char* path);

  void update();

 private:
  char _productNameNT[17] = {'\0'};
  bool _driveConnected = false;
};

}  // namespace apc