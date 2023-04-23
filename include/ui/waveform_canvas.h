#pragma once
#include <audio/waveform.h>
#include <lvgl.h>

#include <vector>

namespace apc {

namespace ui {

class waveform_canvas {
 public:
  waveform_canvas(lv_obj_t* container);

  void set_waveform(const audio::waveform* waveform);

  void update();

 private:
  const audio::waveform* _waveform = nullptr;
  std::vector<uint8_t> _canvasBuffer;
  lv_obj_t* _container;
  lv_obj_t* _canvas;
};

}  // namespace ui
}  // namespace apc
