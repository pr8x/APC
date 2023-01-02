#pragma once
#include <lvgl.h>

#include <functional>

namespace apc {
namespace ui {

class screen;

// typedef void (*screen_close_callback)(screen*);
using screen_close_callback = std::function<void()>;

class screen {
 public:
  screen(lv_obj_t* object) : _object(object) {}

  void set_close_callback(screen_close_callback callback) {
    _closeCallback = callback;
  }

  lv_obj_t* get_object() const { return _object; }

  virtual void update() {}

  virtual const char* name() = 0;

  virtual void load() {}

  virtual void close() {
    if (_closeCallback != nullptr) {
      _closeCallback();
    }
  }

 private:
  screen_close_callback _closeCallback;
  lv_obj_t* _object;
};

}  // namespace ui
}  // namespace apc