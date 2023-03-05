#include <audio/track.h>

apc::audio::track::track(File file, tl::optional<audio::metadata> metadata)
    : _file(std::move(file)), _metadata(std::move(metadata)) {}

File apc::audio::track::file() const { return _file; }

const char* apc::audio::track::file_name() const { return const_cast<File&>(_file).name(); }

const apc::audio::metadata* apc::audio::track::metadata() const {
  return _metadata.has_value() ? &*_metadata : nullptr;
}