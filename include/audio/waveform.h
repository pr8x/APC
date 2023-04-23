#pragma once
#include <FS.h>
#include <audio/mp3_decoder.h>
#include <debug.h>
#include <tl/function_ref.hpp>
#include <algorithm>
#include <vector>

namespace apc {
namespace audio {

class waveform {
 public:
  struct frame {
    uint8_t r = 0, g = 0, b = 0;
    int16_t min, max;
  };

  static waveform generate(File file, tl::function_ref<void(float progress)> progressCallback) {
    waveform wf;

    mp3_decoder decoder(file);

    mp3_decoder::frame frame;
    mp3_decoder::decoding_error error;

    uint64_t bytesRead = 0;
    uint64_t fileSize = file.size();

    while (decoder.decode_frame(frame, error)) {
      APC_LOG_TRACE(
          "mp3 frame: channels: %d bitrate: %d sample rate: %d samples: %d bit "
          "depth: %d",
          frame.info->nChans,
          frame.info->bitrate,
          frame.info->samprate,
          frame.info->outputSamps,
          frame.info->bitsPerSample);

      auto numSamples = frame.samples.size();
      APC_LOG_TRACE(
          "computing waveform window peak for %d samples", numSamples);

      auto [min, max] =
          std::minmax_element(frame.samples.begin(), frame.samples.end());

      auto& wff = wf._frames.emplace_back();
      wff.min = *min;
      wff.max = *max;

      APC_LOG_TRACE("waveform frame: min: %d max: %d", wff.min, wff.max);

      bytesRead += (frame.info->bitsPerSample / 8) * numSamples;

      progressCallback(std::min(bytesRead / (float) fileSize, 1.0f));
    }

    return wf;
  }

  gsl::span<const frame> frames() const { return _frames; }

 private:
  std::vector<frame> _frames;
};
}  // namespace audio
}  // namespace apc