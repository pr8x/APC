#include <USBHost_t36.h>
#include <usb_drive.h>
#include <logger.h>

namespace {
USBHost usbhost;
USBHub hub1(usbhost);
USBHub hub2(usbhost);
USBHub hub3(usbhost);
USBHub hub4(usbhost);
USBDrive drive(usbhost);
USBFilesystem partition(usbhost);
}  // namespace

apc::usb_drive::usb_drive() {
  APC_LOG_INFO("Initializing usb host...");
  usbhost.begin();
}

apc::usb_drive::~usb_drive() = default;

const char* apc::usb_drive::product_name() { return _productNameNT; }

bool apc::usb_drive::is_connected() { return _driveConnected; }

bool apc::usb_drive::is_busy() { return drive.isBusy(); }

File apc::usb_drive::open_path(const char* path) { return partition.open(path); }

void apc::usb_drive::update() {
  usbhost.Task();

  bool isDriveAvailable = drive && partition;

  if (!_driveConnected && isDriveAvailable) {
    _driveConnected = true;

    memcpy(_productNameNT, drive.msDriveInfo.inquiry.ProductID, 16);

    APC_LOG_INFO("USB device connected: %s\n", product_name());
  } else if (_driveConnected && !isDriveAvailable) {
    _driveConnected = false;
    APC_LOG_INFO("USB device disconnected");
  }
}
