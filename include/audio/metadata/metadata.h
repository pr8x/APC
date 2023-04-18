#pragma once
#include <string>
#include <optional>

namespace apc {
namespace audio {

struct metadata {
  std::string artist;
  std::string title;
  std::string album;
  std::optional<uint64_t> lengthMillis;
  std::optional<float> bpm;
  std::string key;
};

}  // namespace audio

}  // namespace apc