#pragma once
#include <lvgl.h>

namespace apc {
namespace ui {

class screen {
 public:
  screen(lv_obj_t* object) : _object(object) {}

  lv_obj_t* get_object() const { return _object; }

 private:
  lv_obj_t* _object;
};

}  // namespace ui
}  // namespace apc