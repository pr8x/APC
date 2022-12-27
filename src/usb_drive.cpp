#include <USBHost_t36.h>
#include <usb_drive.h>

struct apc::usb_drive::impl {
  impl()
      : hub1(usbhost),
        hub2(usbhost),
        hub3(usbhost),
        hub4(usbhost),
        drive(usbhost),
        partition(usbhost) {
    Serial.println("Initializing usb host...");
    usbhost.begin();
  }

  USBHost usbhost;
  USBHub hub1;
  USBHub hub2;
  USBHub hub3;
  USBHub hub4;
  USBDrive drive;
  USBFilesystem partition;
  bool driveConnected = false;
};

apc::usb_drive::usb_drive() { _impl = std::make_unique<impl>(); }

apc::usb_drive::~usb_drive() = default;

const uint8_t* apc::usb_drive::product_name() {
  return _impl->drive.msDriveInfo.inquiry.ProductID;
}

bool apc::usb_drive::is_connected() { return _impl->driveConnected; }

File apc::usb_drive::openPath(const char* path) {
  return _impl->partition.open(path);
}

void apc::usb_drive::update() {
  _impl->usbhost.Task();

  bool isDriveAvailable = _impl->partition;

  if (!_impl->driveConnected && isDriveAvailable) {
    _impl->driveConnected = true;
    Serial.printf("Device connected: %16.16s\n", product_name());
  } else if (_impl->driveConnected && !isDriveAvailable) {
    _impl->driveConnected = false;
    Serial.println("Device disconnected");
  }
}
