#pragma once
#include <Audio.h>
#include <TimeLib.h>
#include <application.h>
#include <stdio.h>
#include <ui/export/ui.h>
#include <ui/screen.h>
#include <InternalTemperature.h>

namespace apc {
namespace ui {
namespace screens {

class diag_screen : public screen {
 public:
  diag_screen() : screen(ui_DiagScreen) {
    _appStartTime = now();
    lv_chart_set_type(ui_DiagScreen_Chart, LV_CHART_TYPE_LINE);
  }

  void update() override {
    char uptimeBuf[16];
    time_t uptime = now() - _appStartTime;
    tm* uptimeTm = localtime(&uptime);
    strftime(uptimeBuf, sizeof(uptimeBuf), "%H:%M:%S", uptimeTm);

    float internalTemp = InternalTemperature.readTemperatureC();

    char statsBuf[2048];
    sprintf(statsBuf, "Audio CPU: %.2f%%\nAudio Memory: %dkB\nUptime: %s\nTemperature: %.2f°C",
            AudioProcessorUsage(), AudioMemoryUsage() / 1024, uptimeBuf);

    lv_label_set_text(ui_DiagScreen_Label, statsBuf);
  }

  const char* name() override { return "diag screen"; }

 private:
  time_t _appStartTime;
};

}  // namespace screens
}  // namespace ui
}  // namespace apc