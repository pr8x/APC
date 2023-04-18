#include <USBHost_t36.h>
#include <logger.h>
#include <usb_drive.h>

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

FS* apc::usb_drive::filesystem() { return &partition; }

uint64_t apc::usb_drive::partition_size() { return partition.totalSize(); }

const char* apc::usb_drive::fat_type() {
  switch (partition.mscfs.fatType()) {
    case FAT_TYPE_EXFAT:
      return "ExFAT";

    case FAT_TYPE_FAT32:

      return "FAT32";

    case FAT_TYPE_FAT16:

      return "FAT16";
  }

  return "Unknown";
}

File apc::usb_drive::open_path(const char* path) {
  return partition.open(path);
}

void apc::usb_drive::update() {
  usbhost.Task();

  bool isDriveAvailable = drive && partition;

  if (!_driveConnected && isDriveAvailable) {
    _driveConnected = true;

    memcpy(_productNameNT, drive.msDriveInfo.inquiry.ProductID, 16);

    APC_LOG_INFO(
        "USB device connected: %s (%s %.2f GB)",
        product_name(),
        fat_type(),
        partition_size() / 1024.0f / 1024.0f / 1024.0f);

  } else if (_driveConnected && !isDriveAvailable) {
    _driveConnected = false;
    APC_LOG_INFO("USB device disconnected");
  }
}
