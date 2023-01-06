#pragma once
#include <FS.h>
#include <minimp3.h>
#include <stdint.h>
#include <string.h>

#include <array>
#include <cassert>
#include <gsl/span>

namespace apc::audio {

template <size_t SampleBlockSize>
class mp3_decoder {
 public:
  mp3_decoder(File file) : _file(file) {
    mp3dec_init(&_dec);
    _fileSize = _file.size();
  }

  gsl::span<int16_t> read_next_block() {
    Serial.printf("Reading sample block: %d\n", _samplesOffset);

    // Check if we need to load more samples
    if (_samplesOffset++ == _samples.size()) {
      if (!read_frame_samples()) {
        return {};
      }
    }

    return gsl::make_span<int16_t>(
        _samples.data() + _samplesOffset, SampleBlockSize);
  }

 private:
  bool read_next_frames() {
    if (_fileOffset == _fileSize) {
      Serial.println("EOF");
      return false;
    }

    Serial.printf("Reading next frames from file: offset: %d\n", _fileOffset);

    // move frames to the left
    memmove(
        _frames.data(), _frames.data() + MinBufferedFrames, MinBufferedFrames);

    // read new frames and place them at the end
    size_t readBytes =
        _file.read(_frames.data() + MinBufferedFrames, MinBufferedFrames);

    Serial.printf("Read %d bytes\n", readBytes);
    _fileOffset += readBytes;

    if (!_file.seek(_fileOffset)) {
      Serial.println("Failed to seek new offset");
      return false;
    }

    return true;
  }

  bool read_frame_samples() {
    assert(_framesOffset <= _frames.size());

    auto remainingFrames = (_frames.size() - _framesOffset) / FrameSize;
    Serial.printf(
        "Reading frame samples: buffered frames: %d\n", remainingFrames);

    if (remainingFrames <= MinBufferedFrames) {
      if (!read_next_frames()) {
        return false;
      }
    }

    mp3dec_frame_info_t info;

    int samplesRead = 0;
    do {
      size_t size =
          std::min(_frames.size() - _framesOffset, _fileSize - _fileOffset);

      samplesRead = mp3dec_decode_frame(
          &_dec, _frames.data() + _framesOffset, size, _samples.data(), &info);

      assert(info.frame_bytes > 0);
      _framesOffset += info.frame_bytes;

      Serial.printf(
          "frame decoded: bytes: %d samples: %d\n",
          info.frame_bytes,
          samplesRead);

      // junk/ID3 is skipped
    } while (samplesRead == 0);

    _samplesOffset = 0;

    return true;
  }

  File _file;
  mp3dec_t _dec;

  static constexpr size_t FrameSampleCount = MINIMP3_MAX_SAMPLES_PER_FRAME;
  static constexpr size_t FrameSize = 1638;  // 1.6Kb
  static constexpr size_t MinBufferedFrames = 10;

  static_assert(
      SampleBlockSize <= FrameSampleCount &&
          FrameSampleCount % SampleBlockSize == 0,
      "SampleBlockSize needs to be divisor of FrameSampleCount (one mp3 "
      "frame)");

  // Recommended to have at least MinBufferedFrames frames in the buffer at a
  // time to prevent sync issues. We use twice the amount so we can refill the
  // buffer later
  std::array<uint8_t, FrameSize * MinBufferedFrames * 2> _frames;
  std::array<int16_t, FrameSampleCount> _samples;

  size_t _samplesOffset{_samples.size()};
  size_t _framesOffset{_frames.size()};
  size_t _fileOffset{0};
  size_t _fileSize{0};
};

}  // namespace apc::audio