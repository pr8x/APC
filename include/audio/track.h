#pragma once
#include <Fs.h>
#include <audio/metadata/metadata.h>

#include <tl/optional.hpp>

namespace apc {
namespace audio {

class track {
 public:
  track(File file, tl::optional<audio::metadata> metadata);

  const char* file_name() const;

  File file() const;

  const apc::audio::metadata* metadata() const;

 private:
  File _file;
  tl::optional<audio::metadata> _metadata;
};

}  // namespace audio
}  // namespace apc