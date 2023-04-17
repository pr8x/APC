#include <audio/metadata/id3_metadata_provider.h>
#include <audio/track_database.h>

const apc::audio::track* apc::audio::track_database::add_track(
    const std::string& path, apc::audio::track track) {
  auto [it, ok] = _tracks.emplace(path, std::move(track));

  if (!ok) {
    return nullptr;
  }

  return &it->second;
}

const apc::audio::track* apc::audio::track_database::find_track(
    const std::string& path) {
  auto it = _tracks.find(path);

  if (it != _tracks.end()) {
    return &it->second;
  }

  return nullptr;
}