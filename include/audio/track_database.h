#pragma once
#include <FS.h>
#include <audio/track.h>

#include <string>
#include <unordered_map>

namespace apc {
namespace audio {

class track_database {
 public:
  const audio::track* add_track(const std::string& path, audio::track track);

  const audio::track* find_track(const std::string& path);

 private:
  std::unordered_map<std::string, audio::track> _tracks;
};

}  // namespace audio
}  // namespace apc
