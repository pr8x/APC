#include <arm_const_structs.h>
#include <arm_math.h>
#include <audio/mp3_decoder.h>
#include <audio/waveform.h>
#include <debug.h>

#include <algorithm>

apc::audio::waveform apc::audio::waveform::generate(
    File file,
    tl::function_ref<void(float progress)> progressCallback,
    waveform_type type) {
  waveform wf;

  mp3_decoder decoder(file);

  mp3_decoder::frame frame;
  mp3_decoder::decoding_error error;

  uint64_t fileSize = file.size();

#if APC_WAVEFORM_FFT_SUPPORT
  constexpr auto FFTSize = 256;

  // imaginary & real buffer combined
  std::vector<short> fftBuffer(FFTSize * 2 + FFTSize);
#endif

  while (decoder.decode_frame(frame, error)) {
    APC_LOG_TRACE(
        "mp3 frame: channels: %d bitrate: %d sample rate: %d samples: %d "
        "resolution: %d Bit",
        frame.info->nChans,
        frame.info->bitrate,
        frame.info->samprate,
        frame.info->outputSamps,
        frame.info->bitsPerSample);

    auto samples = frame.samples;
    auto numSamples = frame.samples.size();
    APC_LOG_TRACE("computing waveform window peak for %d samples", numSamples);

    auto& wff = wf._frames.emplace_back();

    switch (type) {
      case waveform_type::mean:
        arm_mean_q15(samples.data(), numSamples, &wff.v);

        break;

      case waveform_type::rms:
        arm_rms_q15(samples.data(), numSamples, &wff.v);

        break;

      case waveform_type::peak:
      {
        uint32_t _;
        arm_max_q15(samples.data(), numSamples, &wff.v, &_);

        break;
      }
    }

    // APC_LOG_TRACE("waveform frame: min: %d max: %d", wff.min, wff.max);

#if APC_WAVEFORM_FFT_SUPPORT

    auto fftRealBuffer = fftBuffer.data() + FFTSize * 2;
    auto iterations = 0;

    for (size_t i = 0; i < numSamples; i += FFTSize) {
      auto samplesToCopy = std::min<size_t>(numSamples - i, FFTSize);

      APC_TRACE(memcpy(fftBuffer.data(), samples.data() + i, samplesToCopy));

      if (samplesToCopy < FFTSize) {
        APC_LOG_DEBUG("PAD");
        memset(fftBuffer.data() + samplesToCopy, 0, FFTSize - samplesToCopy);
      }

      APC_TRACE(arm_cfft_q15(&arm_cfft_sR_q15_len256, fftBuffer.data(), 0, 1));

      // arm_shift_q15(fftBuffer.data(), 8, fftBuffer.data(), FFTSize);

      APC_TRACE(arm_cmplx_mag_q15(fftBuffer.data(), fftRealBuffer, FFTSize));

      // arm_shift_q15(fftBuffer.data(), 1, fftBuffer.data(), FFTSize);

      Serial.print("FFT:\n\n");
      for (size_t i = 0; i < FFTSize; i++) {
        Serial.printf("%d ", fftRealBuffer[i]);
      }

      auto freqBinRange = FFTSize / 3;

      q15_t low, mid, high;

      APC_TRACE(arm_rms_q15(fftRealBuffer, freqBinRange, &low));
      APC_TRACE(arm_rms_q15(fftRealBuffer + freqBinRange, freqBinRange, &mid));
      APC_TRACE(
          arm_rms_q15(fftRealBuffer + freqBinRange * 2, freqBinRange, &high));

      APC_LOG_DEBUG("low: %d mid: %d high: %d", low, mid, high);

      wff.r += low / __SHRT_MAX__ * 255;
      wff.g += mid / __SHRT_MAX__ * 255;
      wff.b += high / __SHRT_MAX__ * 255;

      iterations++;

      // delay(1000);
    }

    wff.r /= iterations;
    wff.g /= iterations;
    wff.b /= iterations;

#else
    wff.r = 255;
    wff.g = 0;
    wff.b = 0;
#endif

    progressCallback(std::min(decoder.offset() / (float)fileSize, 1.0f));
  }

  wf._frameLengthMillis =
      (frame.info->outputSamps / (float)frame.info->samprate) * 1000;

  return wf;
}

gsl::span<const apc::audio::waveform::frame> apc::audio::waveform::frames()
    const {
  return _frames;
}

uint64_t apc::audio::waveform::frame_length() { return _frameLengthMillis; }
