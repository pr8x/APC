#pragma once
#include <audio/audio_format.h>
#include <audio/metadata/traktor3_metadata_provider.h>
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
  browse_screen(controls* controls, usb_drive* usbDrive);

  const char* name() override;

  void load() override;

  void close() override;

  void set_browse_callback(std::function<void(File)> callback);

  void update() override;

 private:
  void update_path_label();

  void load_files(File& root);

  void add_entry_to_list(File entry, bool isDirectory, audio::metadata* metadata);

  audio::audio_format get_audio_format(File& file);

  void select_item(int index);

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