#pragma once
#include <Audio.h>
#include <InternalTemperature.h>
#include <TimeLib.h>
#include <application.h>
#include <stdio.h>
#include <ui/export/ui.h>
#include <ui/screen.h>
#include <usb_drive.h>

namespace apc {
namespace ui {
namespace screens {

class diag_screen : public screen {
 public:
  diag_screen(usb_drive* usb) : screen(ui_DiagScreen) {
    _appStartTime = now();
    _usb = usb;
  }

  void update() override {
    char uptimeBuf[16];
    time_t uptime = now() - _appStartTime;
    tm* uptimeTm = localtime(&uptime);
    strftime(uptimeBuf, sizeof(uptimeBuf), "%H:%M:%S", uptimeTm);

    float internalTemp = InternalTemperature.readTemperatureC();

    char statsBuf[2048];
    sprintf(
        statsBuf,
        "Uptime: %s\nAudio CPU: %.2f%%\nAudio Memory: %dkB\nTemperature: %.2fC\nUSB: %s",
        uptimeBuf, AudioProcessorUsage(), AudioMemoryUsage() / 1024,
        internalTemp,
        _usb->is_connected() ? _usb->product_name() : "<No USB>");

    lv_label_set_text(ui_DiagScreen_Label, statsBuf);
  }

  const char* name() override { return "diag screen"; }

 private:
  usb_drive* _usb;
  time_t _appStartTime;
};

}  // namespace screens
}  // namespace ui
}  // namespace apc