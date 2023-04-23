#include <ui/waveform_canvas.h>

#include <climits>
#include <debug.h>

apc::ui::waveform_canvas::waveform_canvas(lv_obj_t* container)
    : _container(container) {
  auto containerWidth = 320;  // lv_obj_get_width(_container);
  auto containerHeight = 70;  // lv_obj_get_height(_container);

  _canvas = lv_canvas_create(_container);

  lv_obj_move_background(_canvas);
  lv_obj_set_width(_canvas, lv_pct(100));
  lv_obj_set_height(_canvas, lv_pct(100));

  APC_LOG_TRACE(
      "Allocating waveform canvas buffer (%dx%d)...",
      containerWidth,
      containerHeight);

  _canvasBuffer.resize(
      LV_CANVAS_BUF_SIZE_TRUE_COLOR(containerWidth, containerHeight));

  lv_canvas_set_buffer(
      _canvas,
      _canvasBuffer.data(),
      containerWidth,
      containerHeight,
      LV_IMG_CF_TRUE_COLOR);
}

void apc::ui::waveform_canvas::update() {
  if (!_waveform) {
    return;
  }

  constexpr lv_coord_t BarWidth = 1;
  constexpr lv_coord_t BarSpacing = 1;

  auto w = lv_obj_get_width(_canvas);
  auto h = lv_obj_get_height(_canvas);

  lv_coord_t x = 0;

  lv_draw_rect_dsc_t rectDesc;
  lv_draw_rect_dsc_init(&rectDesc);

  lv_coord_t hh = h / 2;

  for (const auto& frame : _waveform->frames()) {
    float min = ((((float)frame.min) - SHRT_MIN) / SHRT_MAX);
    float max = ((((float)frame.max) - SHRT_MIN) / SHRT_MAX);
    float barHeight = (max - min) * hh;

    rectDesc.bg_color = LV_COLOR_MAKE(frame.r, frame.g, frame.b);

    lv_canvas_draw_rect(
        _canvas, x, hh - barHeight, BarWidth, barHeight, &rectDesc);

    lv_canvas_draw_rect(_canvas, x, hh, BarWidth, barHeight, &rectDesc);

    x += BarWidth + BarSpacing;

    if (x > w) {
      break;
    }
  }
}

void apc::ui::waveform_canvas::set_waveform(const audio::waveform* waveform) {
  _waveform = waveform;
}