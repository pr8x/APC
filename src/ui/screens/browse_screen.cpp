#include <logger.h>
#include <ui/screens/browse_screen.h>

apc::ui::screens::browse_screen::browse_screen(
    controls* controls, usb_drive* usbDrive, audio::track_database* trackDb)
    : screen(ui_BrowseScreen), _trackDb(trackDb) {
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
      APC_LOG_DEBUG("Navigating to parent directory");

      _currentPath.pop_back();
      load_files(_currentPath.back());
      update_path_label();
    } else {
      auto& selectedFile = _files[_lbSelection - (isRoot ? 0 : 1)];

      if (selectedFile.isDirectory()) {
        APC_LOG_DEBUG("Opening directory: %s", selectedFile.name());

        _currentPath.push_back(selectedFile);

        load_files(selectedFile);
        update_path_label();
      } else {
        APC_LOG_DEBUG("Selected file: %s", selectedFile.name());

        if (_browseCallback != nullptr) {
          const auto track = _trackDb->find_track(selectedFile.name());

          if (track) {
            _browseCallback(*track);
          }
        }

        close();
      }
    }
  }
}

void apc::ui::screens::browse_screen::update_path_label() {
  std::string path;

  for (auto& f : _currentPath) {
    path += f.name();
    path += '/';
  }

  lv_label_set_text(ui_BrowseScreen_PathLabel, path.c_str());
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

    const apc::audio::track* track = nullptr;

    if (!isDirectory) {
      std::string path = root.name();
      path += "/";
      path += entry.name();

      APC_LOG_TRACE("%s", path.c_str());

      track = _trackDb->find_track(path);

      if (!track) {
        auto audioFormat = get_audio_format(entry);
        bool isSupported = audioFormat != audio::audio_format::unknown;

        APC_LOG_DEBUG("File: %s (Supported: %d)", entry.name(), isSupported);

        if (!isSupported) {
          continue;
        }

        if (audioFormat == audio::audio_format::mp3) {
          APC_LOG_DEBUG("Reading metadata...");

          auto meta = metaProvider.read_metadata(entry);

          if (meta) {
            APC_LOG_DEBUG(
                "Metadata:\n  Artist: %s\n  Title: %s\n  Album: %s\n  BPM: "
                "%f\n  "
                "Key: %s",
                meta->artist.c_str(),
                meta->title.c_str(),
                meta->album.c_str(),
                meta->bpm,
                meta->key.c_str());
          }

          track = _trackDb->add_track(
              entry.name(),
              audio::track(entry, std::move(path), std::move(meta)));
        }
      }
    }

    add_entry_to_list(entry, isDirectory, track ? track->metadata() : nullptr);

    _files.push_back(entry);
  }

  select_item(0);
}

void apc::ui::screens::browse_screen::add_entry_to_list(
    File entry, bool isDirectory, const audio::metadata* metadata) {
  lv_obj_t* item = lv_obj_create(ui_BrowseScreen_FilesPanel);
  lv_obj_set_flex_flow(item, LV_FLEX_FLOW_ROW);
  lv_obj_set_height(item, 40);

  lv_obj_t* nameLabel = lv_label_create(item);
  lv_label_set_text(nameLabel, entry.name());
  lv_label_set_long_mode(nameLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
  lv_obj_set_align(nameLabel, LV_ALIGN_TOP_LEFT);
  lv_obj_set_flex_grow(nameLabel, 5);

  if (!isDirectory && metadata) {
    lv_obj_t* bpmLabel = lv_label_create(item);

    char bpms[16];
    itoa(metadata->bpm, bpms, 10);
    lv_label_set_text(bpmLabel, bpms);
    lv_obj_set_align(bpmLabel, LV_ALIGN_RIGHT_MID);
    lv_obj_set_flex_grow(bpmLabel, 1);
    lv_obj_set_style_text_color(
        bpmLabel,
        lv_palette_main(LV_PALETTE_LIGHT_GREEN),
        LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t* keyLabel = lv_label_create(item);
    lv_label_set_text(keyLabel, metadata->key.c_str());
    lv_obj_set_align(keyLabel, LV_ALIGN_RIGHT_MID);
    lv_obj_set_flex_grow(keyLabel, 1);
    // lv_obj_set_style_text_color(
    //     keyLabel,
    //     lv_palette_main(LV_PALETTE_LIGHT_GREEN),
    //     LV_PART_MAIN | LV_STATE_DEFAULT);
  }

  lv_obj_set_width(item, LV_PCT(100));
  lv_obj_set_style_radius(item, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(
      item, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
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

  APC_LOG_DEBUG("Selection: %d", index);

  lv_obj_add_style(currentItem, &_lbItemStyleSelected, 0);

  _lbSelection = index;
}

void apc::ui::screens::browse_screen::set_browse_callback(
    std::function<void(const audio::track&)> callback) {
  _browseCallback = std::move(callback);
}

const char* apc::ui::screens::browse_screen::name() { return "browse screen"; }
