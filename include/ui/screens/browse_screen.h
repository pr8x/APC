#pragma once
#include <controls.h>
#include <ui/export/ui.h>
#include <ui/screen.h>
#include <usb_drive.h>
#include <util.h>

#include <vector>

namespace apc {
namespace ui {
namespace screens {

class browse_screen : public screen {
 public:
  browse_screen(controls* controls, usb_drive* usbDrive)
      : screen(ui_BrowseScreen) {
    _controls = controls;
    _usbDrive = usbDrive;

    load_files();

    lv_style_init(&_lbItemStyleSelected);
    lv_style_set_bg_color(&_lbItemStyleSelected,
                          lv_palette_main(LV_PALETTE_RED));
  }

  void update() override {
    auto bkd = _controls->browse_knob.delta();

    if (bkd != 0) {
      if (_selectedFileIndex != -1) {
        auto oldItem = lv_obj_get_child(ui_FilesPanel, _selectedFileIndex);

        lv_obj_remove_style(oldItem, &_lbItemStyleSelected, 0);
      }

      _selectedFileIndex = clamp(_selectedFileIndex + bkd, 0,
                                 static_cast<int>(_files.size()) - 1);

      Serial.printf("Selected file index: %d\n", _selectedFileIndex);

      auto currentItem = lv_obj_get_child(ui_FilesPanel, _selectedFileIndex);

      lv_obj_add_style(currentItem, &_lbItemStyleSelected, 0);
    }

    if (_controls->browse_knob.button()) {
       Serial.printf("Loading file %s\n", _files[_selectedFileIndex]);
    }

  }

  void load_files() {
    _files.reserve(4);
    _files.push_back("J. WEST - Don't you wanna");
    _files.push_back("DRVSH - Burn in my veins");
    _files.push_back("Alec Dienaar - Out Of Print (Chlär Remix)");
    _files.push_back("Pina Tesla - Solid State");

    for (auto file : _files) {
      lv_list_add_text(ui_FilesPanel, file);
    }
  }

 private:
  lv_style_t _lbItemStyleSelected;

  std::vector<const char*> _files;
  int _selectedFileIndex = -1;

  controls* _controls;
  usb_drive* _usbDrive;
};

}  // namespace screens
}  // namespace ui
}  // namespace apc