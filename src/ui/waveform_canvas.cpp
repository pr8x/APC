#include <debug.h>
#include <ui/waveform_canvas.h>

#include <climits>
#include <util.h>

#undef abs

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

void apc::ui::waveform_canvas::set_offset(uint64_t millis) { _offset = millis; }

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

  lv_canvas_fill_bg(_canvas, lv_color_black(), 0x0);

  auto frames = _waveform->frames();
  uint64_t frameOffset = _offset / _waveform->frame_length();

  for (auto i = frameOffset; i < frames.size(); i++) {
    const auto& frame = frames[i];
    float barHeight = util::map<int16_t>(frame.v, SHRT_MIN, SHRT_MAX, 0, hh);

    rectDesc.bg_color = LV_COLOR_MAKE(frame.r, frame.g, frame.b);

    // APC_LOG_DEBUG("COLOR: %d %d %d", frame.r, frame.g, frame.b);

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