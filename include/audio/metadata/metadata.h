#pragma once
#include <string>

namespace apc {
namespace audio {

struct metadata {
  std::string artist;
  std::string title;
  std::string album;
  float bpm = -1;
  std::string key;
};

}  // namespace audio

}  // namespace apc