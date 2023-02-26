#pragma once
#include <FS.h>
#include <audio/metadata/id3_metadata_provider.h>

#include <algorithm>
#include <array>
#include <iterator>
#include <string>

namespace apc {
namespace audio {

class traktor3_metadata_provider final : public id3_metadata_provider {
 public:
  metadata read_metadata(File& file) override {
    // https://hellricer.github.io/2021/05/05/decoding-traktor4-field.html
    // ID3v2_Frame* privFrame =
    //     ID3v2_Tag_get_frame(tag, "PRIV");

    // if (privFrame != nullptr) {
    //   auto stream = (char*)privFrame->data;
    //   Serial.printf("PRIV frame detected: %.*s\n", 10, stream);

    //   if (strcmp(stream, "TRAKTOR4") == 0) {
    //     stream += 9;

    //     auto rootFrame = read_traktor4_frame(stream);
    //     auto hdrFrame = read_traktor4_frame(stream);

    //     // Skip header frame data
    //     stream += hdrFrame.frameLength;

    //     auto dataFrame = read_traktor4_frame(stream);
    //   }
    // }

    return id3_metadata_provider::read_metadata(file);
  }

  struct traktor4_frame {
    char frameId[4];
    uint32_t frameLength;
    uint32_t numChildFrames;
  };

  traktor4_frame read_traktor4_frame(char*& stream) {
    traktor4_frame frame;

    read_bytes(stream, frame.frameId);
    std::reverse(std::begin(frame.frameId), std::end(frame.frameId));
    Serial.printf("TRAKTOR frame id: %.*s\n", 4, frame.frameId);

    frame.frameLength = read_bytes<uint32_t>(stream);
    Serial.printf("TRAKTOR frame length: %u\n", frame.frameLength);

    frame.numChildFrames = read_bytes<uint32_t>(stream);
    Serial.printf("TRAKTOR child frames: %u\n", frame.numChildFrames);

    return frame;
  }

  template <class T>
  T read_bytes(char*& stream) {
    T* p = reinterpret_cast<T*>(stream);
    stream += sizeof(T);
    return *p;
  }

  template <size_t N>
  void read_bytes(char*& stream, char (&arr)[N]) {
    memcpy(arr, stream, N);
    stream += N;
  }
};

}  // namespace audio
}  // namespace apc