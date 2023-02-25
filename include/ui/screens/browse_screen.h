#pragma once
#include <controls/controls.h>
#include <string.h>
#include <ui/export/ui.h>
#include <ui/screen.h>
#include <usb_drive.h>
#include <util.h>

#include <functional>
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
    lv_style_set_bg_color(
        &_lbItemStyleSelected, lv_palette_main(LV_PALETTE_RED));
  }

  const char* name() override { return "browse screen"; }

  void load() override {
    screen::load();

    lv_label_set_text(ui_BrowseScreen_USBLabel, _usbDrive->product_name());

    auto root = _usbDrive->open_path("/");
    load_files(root);

    _currentPath.push_back(root);
    update_path_label();
  }

  void close() override {
    screen::close();

    _files.clear();
    _currentPath.clear();
  }

  void set_browse_callback(std::function<void(File)> callback) {
    _browseCallback = std::move(callback);
  }

  void update() override {
    screen::update();

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

      auto index = clamp<uint32_t>(
          _lbSelection + bkd,
          0,
          lv_obj_get_child_cnt(ui_BrowseScreen_FilesPanel) - 1);

      select_item(index);
    }

    if (_controls->browse_knob.button.is_down()) {
      //".."
      if (!isRoot && _lbSelection == 0) {
        Serial.println("Navigating to parent directory");

        _currentPath.pop_back();
        load_files(_currentPath.back());
        update_path_label();
      } else {
        auto& selectedFile = _files[_lbSelection - (isRoot ? 0 : 1)];

        if (selectedFile.isDirectory()) {
          Serial.printf("Opening directory: %s\n", selectedFile.name());

          _currentPath.push_back(selectedFile);

          load_files(selectedFile);
          update_path_label();
        } else {
          Serial.printf("Selected file: %s\n", selectedFile.name());

          if (_browseCallback != nullptr) {
            _browseCallback(selectedFile);
          }
          close();
        }
      }
    }
  }

  void update_path_label() {
    char path[1024] = {'\0'};
    char* p = path;

    for (auto& f : _currentPath) {
      auto fileName = f.name();
      auto len = strlen(fileName);
      memcpy(p, fileName, len);
      p += len;
      *(p) = '/';
    }

    lv_label_set_text(ui_BrowseScreen_PathLabel, path);
  }

  void load_files(File& root) {
    _files.clear();

    lv_obj_clean(ui_BrowseScreen_FilesPanel);

    if (_currentPath.size() > 1) {
      lv_list_add_text(ui_BrowseScreen_FilesPanel, "..");
    }

    File entry;

    root.rewindDirectory();

    while ((entry = root.openNextFile())) {
      bool isSupported = filter_file(entry);
      Serial.printf("File: %s (Supported: %d)\n", entry.name(), isSupported);

      if (!isSupported) {
        continue;
      }

      lv_list_add_text(ui_BrowseScreen_FilesPanel, entry.name());
      _files.push_back(entry);
    }

    select_item(0);
  }

  bool filter_file(File& file) {
    if (file.isDirectory()) {
      return true;
    }

    auto fe = strrchr(file.name(), '.');

    return strcmp(fe, ".wav") == 0 || strcmp(fe, ".mp3") == 0;
  }

  void select_item(int index) {
    auto currentItem = lv_obj_get_child(ui_BrowseScreen_FilesPanel, index);

    Serial.printf("Selection: %d\n", index);

    lv_obj_add_style(currentItem, &_lbItemStyleSelected, 0);

    _lbSelection = index;
  }

 private:
  lv_style_t _lbItemStyleSelected;

  std::vector<File> _currentPath;
  std::vector<File> _files;
  int _lbSelection = -1;

  controls* _controls;
  usb_drive* _usbDrive;

  std::function<void(File)> _browseCallback;
};

}  // namespace screens
}  // namespace ui
}  // namespace apc