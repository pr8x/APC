#include <ui/screens/diag_screen.h>
#include <InternalTemperature.h>

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
  int usedRamKb = ramAvailable() / 1024;

  char statsBuf[2048];
  sprintf(
      statsBuf,
      "Uptime: %s\nRAM Used: %dKb (%.2f%%)\nAudio CPU: %.2f%%\nAudio Memory: "
      "%dkB\nTemperature: %.2fC\nUSB: %s",
      uptimeBuf,
      usedRamKb,
      usedRamKb * 100.0f / totalRamKb,
      AudioProcessorUsage(),
      AudioMemoryUsage() / 1024,
      internalTemp,
      _usb->is_connected() ? _usb->product_name() : "<No USB>");

  lv_label_set_text(ui_DiagScreen_Label, statsBuf);
}

const char* apc::ui::screens::diag_screen::name() { return "diag screen"; }
