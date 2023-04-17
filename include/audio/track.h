#pragma once
#include <Fs.h>
#include <audio/metadata/metadata.h>

#include <optional>

namespace apc {
namespace audio {

class track {
 public:
  track(File file, std::string path, std::optional<audio::metadata> metadata);

  const char* file_name() const;

  const char* full_path() const;

  File file() const;

  const apc::audio::metadata* metadata() const;

 private:
  File _file;
  std::string _path;
  std::optional<audio::metadata> _metadata;
};

}  // namespace audio
}  // namespace apc