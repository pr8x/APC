#include <ui/waveform_canvas.h>

apc::ui::waveform_canvas::waveform_canvas(lv_obj_t* canvas) : _canvas(canvas) {}

void apc::ui::waveform_canvas::update() {
  if (!_waveform) {
    return;
  }

  constexpr lv_coord_t BarWidth = 1;
  constexpr lv_coord_t BarSpacing = 1;

  auto h = lv_obj_get_height(_canvas);

  lv_coord_t x = 0;

  lv_draw_rect_dsc_t rectDesc;
  lv_draw_rect_dsc_init(&rectDesc);

  rectDesc.bg_color = lv_palette_main(LV_PALETTE_CYAN);

  for (const auto& frame : _waveform->frames()) {
    lv_canvas_draw_rect(_canvas, x, h / 2 - frame.lh * h / 2, BarWidth, frame.lh * h / 2, nullptr);
    lv_canvas_draw_rect(_canvas, x, h / 2, BarWidth, frame.rh * h / 2, nullptr);

    x += BarWidth + BarSpacing;
  }
}

void apc::ui::waveform_canvas::set_waveform(const audio::waveform* waveform) {
  _waveform = waveform;
}