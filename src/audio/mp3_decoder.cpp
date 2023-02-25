#include <audio/mp3_decoder.h>

#define MINIMP3_IMPLEMENTATION
#define MINIMP3_NO_SIMD
#define MINIMP3_ONLY_MP3
#include <minimp3.h>

apc::audio::mp3_decoder::mp3_decoder(File file, size_t sampleBlockSize)
    : _file(std::move(file)) {
  mp3dec_init(&_dec);
  
  _sampleBlockSize = sampleBlockSize;
  _fileOffset = 0;
  _fileSize = _file.size();

  _frames =
      (uint8_t*)malloc(EstimatedFrameSize * BufferedFrames * sizeof(uint8_t));
  _samples = (int16_t*)malloc(FrameMaxSampleCount * sizeof(int16_t));

  _frameSampleCount = 0;
  _frameInfo = {};

  _sampleOffset = 0;
  _framesOffset = EstimatedFrameSize * BufferedFrames;
}

apc::audio::mp3_decoder::block apc::audio::mp3_decoder::read_next_block() {
  if (_fileOffset == 0) {
    // Load some initial frames
    Serial.println("Loading initial frames");
    if (!read_next_frames()) {
      return {};
    }
  }

  // Check if we need to load more samples
  auto remainingSamples = _frameSampleCount - _sampleOffset;

  if (remainingSamples < _sampleBlockSize) {
    Serial.printf(
        "Not enough samples buffered (%d). Reading more samples\n",
        remainingSamples);

    if (!decode_frame()) {
      return {};
    }
  }

  Serial.printf("Reading sample block at: %d\n", _sampleOffset);

  block block{};

  block.leftChannel =
      gsl::make_span<int16_t>(_samples + _sampleOffset, _sampleBlockSize);

  if (_frameInfo.channels == 2) {
    block.rightChannel = gsl::make_span<int16_t>(
        _samples + _frameSampleCount + _sampleOffset, _sampleBlockSize);
  }

  _sampleOffset += _sampleBlockSize;

  return block;
}

bool apc::audio::mp3_decoder::read_next_frames() {
  if (_fileOffset == _fileSize) {
    Serial.println("EOF");
    return false;
  }

  assert(_framesOffset > 0);

  // APC_BREAKPOINT;

  if (_framesOffset < EstimatedFrameSize * BufferedFrames) {
    auto unconsumedFrames = EstimatedFrameSize * BufferedFrames - _framesOffset;
    Serial.printf(
        "Moving %d unconsumed frames to beginning\n", unconsumedFrames);

    // Move unused frames to the beginning
    memmove(_frames, _frames + _framesOffset, unconsumedFrames);
  } else {
    _framesOffset = 0;
  }

  auto size = EstimatedFrameSize * BufferedFrames;
  Serial.printf("Reading file: offset: %d size: %d\n", _fileOffset, size);
  size_t readBytes = _file.read(_frames, size);
  Serial.printf("Read %d bytes\n", readBytes);

  _fileOffset += readBytes;
  _framesOffset = 0;

  return true;
}

bool apc::audio::mp3_decoder::decode_frame() {
  assert(_framesOffset <= EstimatedFrameSize * BufferedFrames);

  int samplesRead = 0;

  do {
    size_t size = std::min(
        EstimatedFrameSize * BufferedFrames - _framesOffset,
        _fileSize - _fileOffset);

    Serial.printf(
        "Decoding frame at offset: %d size: %d\n", _framesOffset, size);

    samplesRead = mp3dec_decode_frame(
        &_dec, _frames + _framesOffset, size, _samples, &_frameInfo);

    if (samplesRead == 0 && _frameInfo.frame_bytes == 0) {
      Serial.println("Insufficient frame data");

      if (!read_next_frames()) {
        return false;
      }
    } else {
      _framesOffset += _frameInfo.frame_bytes;

      Serial.printf(
          "Frame decoded: bytes: %d samples: %d channels: %d bitrate: %dkbps\n",
          _frameInfo.frame_bytes,
          samplesRead,
          _frameInfo.channels,
          _frameInfo.bitrate_kbps);
    }

    // junk/ID3 data is skipped
  } while (samplesRead == 0);

  _frameSampleCount = samplesRead;
  _sampleOffset = 0;

  return true;
}