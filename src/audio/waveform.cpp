#include <audio/mp3_decoder.h>
#include <audio/waveform.h>
#include <debug.h>

#include <algorithm>

#if APC_WAVEFORM_FFT_SUPPORT
#include <arm_math.h>
#endif

apc::audio::waveform apc::audio::waveform::generate(
    File file, tl::function_ref<void(float progress)> progressCallback) {
  waveform wf;

  mp3_decoder decoder(file);

  mp3_decoder::frame frame;
  mp3_decoder::decoding_error error;

  uint64_t fileSize = file.size();

#if APC_WAVEFORM_FFT_SUPPORT
  constexpr auto FFTSize = 256;

//   int16_t fftInputBuffer[FFTSize];
//   int16_t fftOutputBuffer[FFTSize / 2];

  arm_cfft_radix4_instance_q15 fft;
  arm_cfft_radix4_init_q15(&fft, FFTSize, 0, 1);
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

    auto numSamples = frame.samples.size();
    APC_LOG_TRACE("computing waveform window peak for %d samples", numSamples);

    auto [min, max] =
        std::minmax_element(frame.samples.begin(), frame.samples.end());

    auto& wff = wf._frames.emplace_back();
    wff.min = *min;
    wff.max = *max;

    APC_LOG_TRACE("waveform frame: min: %d max: %d", wff.min, wff.max);

#if APC_WAVEFORM_FFT_SUPPORT
    // for (size_t i = 0; i < numSamples; i += FFTSize) {
    //   memcpy(
    //       fftInputBuffer,
    //       frame.samples.data() + i,
    //       std::min<size_t>(numSamples - i, FFTSize));

    //   arm_cfft_radix4_q15(&fft, fftInputBuffer);
    //   arm_cmplx_mag_q15(fftInputBuffer, fftOutputBuffer, FFTSize);

    //   for (size_t k = 0; k < FFTSize / 2; k++) {
    //     APC_LOG_DEBUG("%d", fftOutputBuffer[k]);
    //   }
    // }
#else
    wff.r = 255;
    wff.g = 0;
    wff.b = 0;
#endif

    progressCallback(std::min(decoder.offset() / (float)fileSize, 1.0f));
  }

  return wf;
}
