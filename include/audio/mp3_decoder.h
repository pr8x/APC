#pragma once
#include <FS.h>
#include <debug.h>
#include <mp3/mp3dec.h>

#include <gsl/span>
#include <tl/function_ref.hpp>
#include <vector>

namespace apc::audio {

class mp3_decoder {
 public:
  mp3_decoder(File file) {
    _decoder = APC_TRACE(MP3InitDecoder());
    _file = file;
    _buffer.resize(MAINBUF_SIZE * 2);
    _samples.resize(2304);
  }

  using decoding_error = decltype(ERR_MP3_NONE);

  struct frame {
    MP3FrameInfo* info;
    gsl::span<short> samples;
  };

  bool decode_frame(frame& outFrame, decoding_error& outError) {
    if (_remainingBytes < MAINBUF_SIZE) {
      if (!_file.available()) {
        APC_LOG_TRACE("EOF");
        return false;
      }

      if (_remainingBytes > 0) {
        APC_LOG_TRACE(
            "moving remaining bytes to beginning: %d", _remainingBytes);

        memmove(_buffer.data(), _bufferOffset, _remainingBytes);
      }

      auto bytesRead = APC_TRACE(_file.readBytes(
          _buffer.data() + _remainingBytes, _buffer.size() - _remainingBytes));

      APC_LOG_TRACE("Read %d bytes from file", bytesRead);

      _remainingBytes += bytesRead;
      _bufferOffset = (unsigned char*)_buffer.data();
    }

    int frameOffset =
        APC_TRACE(MP3FindSyncWord(_bufferOffset, _remainingBytes));

    if (frameOffset < 0) {
      APC_LOG_TRACE("no sync found, eof");
      return false;
    }

    APC_LOG_TRACE("frame found at offset %d", frameOffset);

    _bufferOffset += frameOffset;
    _remainingBytes -= frameOffset;

    outError = (decoding_error)APC_TRACE(MP3Decode(
        _decoder, &_bufferOffset, &_remainingBytes, _samples.data(), 0));

    if (outError != ERR_MP3_NONE) {
      APC_LOG_ERROR("Decoder error: %d", outError);

      return false;
    }

    APC_TRACE(MP3GetLastFrameInfo(_decoder, &_frameInfo));

    outFrame.info = &_frameInfo;
    outFrame.samples = gsl::make_span(_samples.data(), _frameInfo.outputSamps);

    return true;
  }

 private:
  File _file;
  HMP3Decoder _decoder;
  MP3FrameInfo _frameInfo;
  std::vector<char> _buffer;
  std::vector<short> _samples;

  unsigned char* _bufferOffset = nullptr;
  int _remainingBytes = 0;
};

}  // namespace apc::audio