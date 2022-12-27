#pragma once
#include <memory>
#include <ui/screen.h>

namespace apc {
namespace ui {

struct display_config {
  int8_t cs;
  int8_t dc;
  int8_t mosi;
  int8_t sclk;
  int8_t rst;
};

class display_driver {
 public:
  display_driver(const display_config& config);
  ~display_driver();

  void set_screen(const screen* screen);

  void update();

 private:
  struct impl;
  std::unique_ptr<impl> _impl;
};
}  // namespace ui
}  // namespace apc