#include <Arduino.h>
#include <InternalTemperature.h>
#include <ui/screens/diag_screen.h>
#include <util.h>

extern unsigned long _heap_start;
extern unsigned long _heap_end;
extern char* __brkval;

namespace {

int ramAvailable() { return (char*)&_heap_end - __brkval; }

}  // namespace

apc::ui::screens::diag_screen::diag_screen(usb_drive* usb)
    : screen(ui_DiagScreen) {
  _appStartTime = now();
  _usb = usb;
}

void apc::ui::screens::diag_screen::update() {
  char uptimeBuf[16];
  time_t uptime = now() - _appStartTime;
  tm* uptimeTm = localtime(&uptime);
  strftime(uptimeBuf, sizeof(uptimeBuf), "%H:%M:%S", uptimeTm);

  float internalTemp = InternalTemperature.readTemperatureC();

  int totalRamKb = 1024;  // 512K + 512K
  int usedRamKb = (int) ceil(ramAvailable() / 1024.0f);

  fixed_string_builder<2048> sb;

  sb.append_format("Uptime: %s\n", uptimeBuf);
  sb.append_format(
      "RAM Used: %dKb (%.2f%%)\n", usedRamKb, usedRamKb * 100.0f / totalRamKb);
  sb.append_format("Audio CPU: %.2f%%\n", AudioProcessorUsage());
  sb.append_format("Audio Memory: %dkB\n", AudioMemoryUsage() / 1024);
  sb.append_format("Temperature: %.2fC\n", internalTemp);

  if (_usb->is_connected()) {
    sb.append_format(
        "USB: %s (%s %.2fGB) \n",
        _usb->product_name(),
        _usb->fat_type(),
        _usb->partition_size() / 1024.0f / 1024.0f / 1024.0f);
  } else {
    sb.append_format("USB: <No USB>\n");
  }

  lv_label_set_text(ui_DiagScreen_Label, sb.str());
}

const char* apc::ui::screens::diag_screen::name() { return "diag screen"; }
