#pragma once
#include <FS.h>
#include <minimp3.h>
#include <stdint.h>
#include <string.h>

#include <array>
#include <cassert>
#include <gsl/span>

namespace apc {
namespace audio {

template <size_t SampleBlockSize>
class mp3_decoder {
 public:
  mp3_decoder(File file) : _file(file) {
    mp3dec_init(&_dec);
    _fileSize = _file.size();
  }

  gsl::span<int16_t> read_next_block() {
    // Check if we need to load more samples
    if (_samplesOffset == _samples.size() - 1) {
      read_frame_samples();
    }

    _samplesOffset += SampleBlockSize;

    return gsl::make_span<int16_t>(
        _samples.data() + _samplesOffset, SampleBlockSize);
  }

 private:
  int read_next_frames() {
    // move frames to the left
    memmove(
        _frames.data(), _frames.data() + MinBufferedFrames, MinBufferedFrames);

    // read new frames and place them at the end
    return _file.read(_frames.data() + MinBufferedFrames, MinBufferedFrames);
  }

  void read_frame_samples() {
    assert(_framesOffset < _frames.size());

    auto remainingFrames = (_frames.size() - _framesOffset) / FrameSize;
    if (remainingFrames <= MinBufferedFrames) {
      read_next_frames();
    }

    mp3dec_frame_info_t info;

    int samplesRead = 0;
    do {
      samplesRead = mp3dec_decode_frame(
          &_dec,
          _frames.data() + _framesOffset,
          _frames.size() - _framesOffset,
          _samples.data(),
          &info);

      assert(info.frame_bytes > 0);
      _framesOffset += info.frame_bytes;

      // junk/ID3 is skipped
    } while (samplesRead == 0);
  }

  File _file;
  mp3dec_t _dec;

  static constexpr size_t FrameSampleCount = MINIMP3_MAX_SAMPLES_PER_FRAME;
  static constexpr size_t FrameSize = 1638;  // 1.6Kb
  static constexpr size_t MinBufferedFrames = 10;

  static_assert(
      SampleBlockSize <= FrameSampleCount &&
          FrameSampleCount % SampleBlockSize == 0,
      "SampleBlockSize needs to be divisor of FrameSampleCount (one mp3 frame)");

  // Recommended to have at least MinBufferedFrames frames in the buffer at a
  // time to prevent sync issues. We use twice the amount so we can refill the
  // buffer later
  std::array<uint8_t, FrameSize * MinBufferedFrames * 2> _frames;
  std::array<int16_t, FrameSampleCount> _samples;

  size_t _samplesOffset{_samples.size() - 1};
  size_t _framesOffset{_frames.size() - 1};
  size_t _fileOffset{0};
  size_t _fileSize{0};
};
}  // namespace audio
}  // namespace apc