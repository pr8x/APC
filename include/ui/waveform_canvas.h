#pragma once
#include <audio/waveform.h>
#include <lvgl.h>

namespace apc {

namespace ui {

class waveform_canvas {
 public:
  waveform_canvas(lv_obj_t* canvas);

  void set_waveform(const audio::waveform* waveform);

  void update();

 private:
  const audio::waveform* _waveform;
  lv_obj_t* _canvas;
};

}  // namespace ui
}  // namespace apc
