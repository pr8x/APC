#include <ui/screens/browse_screen.h>

apc::ui::screens::browse_screen::browse_screen(
    controls* controls, usb_drive* usbDrive)
    : screen(ui_BrowseScreen) {
  _controls = controls;
  _usbDrive = usbDrive;

  lv_style_init(&_lbItemStyleSelected);
  lv_style_set_bg_color(&_lbItemStyleSelected, lv_palette_main(LV_PALETTE_RED));
}

void apc::ui::screens::browse_screen::load() {
  screen::load();

  lv_label_set_text(ui_BrowseScreen_USBLabel, _usbDrive->product_name());

  auto root = _usbDrive->open_path("/");
  load_files(root);

  _currentPath.push_back(root);
  update_path_label();
}

void apc::ui::screens::browse_screen::close() {
  screen::close();

  _files.clear();
  _currentPath.clear();
}

void apc::ui::screens::browse_screen::update() {
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
      auto oldItem = lv_obj_get_child(ui_BrowseScreen_FilesPanel, _lbSelection);

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

void apc::ui::screens::browse_screen::update_path_label() {
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

void apc::ui::screens::browse_screen::load_files(File& root) {
  _files.clear();

  lv_obj_clean(ui_BrowseScreen_FilesPanel);

  if (_currentPath.size() > 1) {
    lv_list_add_text(ui_BrowseScreen_FilesPanel, "..");
  }

  File entry;

  root.rewindDirectory();

  audio::traktor3_metadata_provider metaProvider;

  while ((entry = root.openNextFile())) {
    bool isDirectory = entry.isDirectory();

    tl::optional<apc::audio::metadata> metadata;

    if (!isDirectory) {
      auto audioFormat = get_audio_format(entry);
      bool isSupported = audioFormat != audio::audio_format::unknown;

      Serial.printf("File: %s (Supported: %d)\n", entry.name(), isSupported);

      if (!isSupported) {
        continue;
      }

      if (audioFormat == audio::audio_format::mp3) {
        Serial.printf("Reading metadata...\n");

        metadata = metaProvider.read_metadata(entry);

        if (metadata) {
          Serial.printf(
              "Metadata:\n  Artist: %s\n  Title: %s\n  Album: %s\n  BPM: %f\n  "
              "Key: %s\n",
              metadata->artist.c_str(),
              metadata->title.c_str(),
              metadata->album.c_str(),
              metadata->bpm,
              metadata->key.c_str());
        }
      }
    }

    add_entry_to_list(entry, isDirectory, metadata);

    // lv_list_add_text(ui_BrowseScreen_FilesPanel, entry.name());

    _files.push_back(entry);
  }

  select_item(0);
}

void apc::ui::screens::browse_screen::add_entry_to_list(
    File entry, bool isDirectory, tl::optional<audio::metadata> metadata) {
  auto sg = lv_spangroup_create(ui_BrowseScreen_FilesPanel);

  auto nameLabel = lv_spangroup_new_span(sg);
  lv_span_set_text(nameLabel, entry.name());

  if (!isDirectory && metadata) {
    auto bpmLabel = lv_spangroup_new_span(sg);

    char bpms[16];
    itoa(metadata->bpm, bpms, 10);
    lv_span_set_text(bpmLabel, bpms);

    lv_style_set_text_color(
        &bpmLabel->style, lv_palette_main(LV_PALETTE_LIGHT_GREEN));
  }

  lv_obj_set_width(sg, LV_PCT(100));
}

apc::audio::audio_format apc::ui::screens::browse_screen::get_audio_format(
    File& file) {
  auto fe = strrchr(file.name(), '.');

  if (strcmp(fe, ".wav") == 0) {
    return audio::audio_format::wav;
  }

  if (strcmp(fe, ".mp3") == 0) {
    return audio::audio_format::mp3;
  }

  return audio::audio_format::unknown;
}

void apc::ui::screens::browse_screen::select_item(int index) {

  auto currentItem = lv_obj_get_child(ui_BrowseScreen_FilesPanel, index);

  Serial.printf("Selection: %d\n", index);

  lv_obj_add_style(currentItem, &_lbItemStyleSelected, 0);

  _lbSelection = index;
}

void apc::ui::screens::browse_screen::set_browse_callback(
    std::function<void(File)> callback) {
  _browseCallback = std::move(callback);
}

const char* apc::ui::screens::browse_screen::name() { return "browse screen"; }
