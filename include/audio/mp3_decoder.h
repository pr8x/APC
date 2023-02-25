#pragma once
#include <FS.h>
#include <debugger.h>
#include <minimp3.h>
#include <stdint.h>
#include <string.h>

#include <cassert>
#include <gsl/span>

namespace apc {
namespace audio {

class mp3_decoder {
 public:
 
  struct block {
    gsl::span<int16_t> leftChannel;
    gsl::span<int16_t> rightChannel;
  };

  mp3_decoder(File file, size_t sampleBlockSize);

  block read_next_block();

 private:
  bool read_next_frames();

  bool decode_frame();

 private:
  File _file;
  mp3dec_t _dec;

  static constexpr size_t FrameMaxSampleCount = MINIMP3_MAX_SAMPLES_PER_FRAME;
  static constexpr size_t EstimatedFrameSize = 1638;  // 1.6Kb
  static constexpr size_t BufferedFrames = 10;

  // static_assert(
  //     SampleBlockSize <= FrameSampleCount &&
  //         FrameSampleCount % SampleBlockSize == 0,
  //     "SampleBlockSize needs to be divisor of FrameSampleCount (one mp3 "
  //     "frame)");

  size_t _sampleBlockSize;

  uint8_t* _frames;
  int16_t* _samples;
  mp3dec_frame_info_t _frameInfo;
  size_t _frameSampleCount;

  size_t _sampleOffset;
  size_t _framesOffset;
  size_t _fileOffset;
  size_t _fileSize;
};

}  // namespace audio
}  // namespace apc