#include <audio/track.h>

apc::audio::track::track(File file, std::string path, std::optional<audio::metadata> metadata)
    : _file(std::move(file)), _path(std::move(path)), _metadata(std::move(metadata)) {}

File apc::audio::track::file() const { return _file; }

const char* apc::audio::track::file_name() const {
  return const_cast<File&>(_file).name();
}

const char* apc::audio::track::full_path() const { return _path.c_str(); }

const apc::audio::metadata* apc::audio::track::metadata() const {
  return _metadata.has_value() ? &*_metadata : nullptr;
}
