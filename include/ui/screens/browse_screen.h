#pragma once
#include <controls/controls.h>
#include <ui/export/ui.h>
#include <ui/screen.h>
#include <usb_drive.h>
#include <util.h>

#include <functional>
#include <stack>
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

    lv_style_init(&_lbItemStyleSelected);
    lv_style_set_bg_color(&_lbItemStyleSelected,
                          lv_palette_main(LV_PALETTE_RED));
  }

  const char* name() override { return "browse screen"; }

  void load() override {
    lv_label_set_text(ui_BrowseScreen_USBLabel, _usbDrive->product_name());
    load_files(_usbDrive->openPath("/"));
  }

  void set_browse_callback(std::function<void(File)> callback) {
    _browseCallback = callback;
  }

  void update() override {
    if (_usbDrive->is_busy()) {
      lv_obj_clear_flag(ui_BrowseScreen_USBIndicator, LV_OBJ_FLAG_HIDDEN);
    } else {
      lv_obj_add_flag(ui_BrowseScreen_USBIndicator, LV_OBJ_FLAG_HIDDEN);
    }

    auto bkd = _controls->browse_knob.delta();
    bool isRoot = _currentPath.size() == 1;

    if (bkd != 0) {
      if (_lbSelection != -1) {
        auto oldItem =
            lv_obj_get_child(ui_BrowseScreen_FilesPanel, _lbSelection);

        lv_obj_remove_style(oldItem, &_lbItemStyleSelected, 0);
      }

      _lbSelection =
          clamp<uint32_t>(_lbSelection + bkd, 0,
                          lv_obj_get_child_cnt(ui_BrowseScreen_FilesPanel));

      Serial.printf("Selection: %d\n", _lbSelection);

      auto currentItem =
          lv_obj_get_child(ui_BrowseScreen_FilesPanel, _lbSelection);

      lv_obj_add_style(currentItem, &_lbItemStyleSelected, 0);
    }

    if (_controls->browse_knob.button.is_down()) {
      //".."
      if (!isRoot && _lbSelection == 0) {
        _currentPath.pop();
        load_files(_currentPath.top());
      } else {
        auto selectedFile = _files[_lbSelection - (isRoot ? 0 : 1)];

        if (selectedFile.isDirectory()) {
          load_files(selectedFile);
        } else {
          if (_browseCallback != nullptr) {
            _browseCallback(selectedFile);
          }
          close();
        }
      }
    }
  }

  void load_files(File root) {
    _files.clear();
    _currentPath.push(root);

    for (uint32_t i = 0; i < lv_obj_get_child_cnt(ui_BrowseScreen_FilesPanel);
         i++) {
      lv_obj_del(lv_obj_get_child(ui_BrowseScreen_FilesPanel, i));
    }

    if (_currentPath.size() > 1) {
      lv_list_add_text(ui_BrowseScreen_FilesPanel, "..");
    }

    File entry;

    while ((entry = root.openNextFile())) {
      Serial.printf("File: %s\n", entry.name());
      _files.push_back(entry);
      lv_list_add_text(ui_BrowseScreen_FilesPanel, entry.name());
    }
  }

 private:
  lv_style_t _lbItemStyleSelected;

  std::stack<File> _currentPath;
  std::vector<File> _files;
  int _lbSelection = -1;

  controls* _controls;
  usb_drive* _usbDrive;

  std::function<void(File)> _browseCallback;
};

}  // namespace screens
}  // namespace ui
}  // namespace apc