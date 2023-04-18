#pragma once
#include <Audio.h>
#include <SD.h>
#include <SPI.h>
#include <SerialFlash.h>
#include <Wire.h>
#include <audio/usb_audio_stream.h>
#include <config.h>
#include <logger.h>
#include <play_sd_mp3.h>

namespace apc {
namespace audio {
class audio_graph {
 public:
  audio_graph() {
    APC_LOG_INFO("Creating audio graph...");
    APC_LOG_DEBUG("Audio memory blocks: %d", AudioMemoryBlocks);
    AudioMemory(AudioMemoryBlocks);
  }

  // GUItool: begin automatically generated code
  AudioPlaySdMp3 Deck_B;           // xy=535.0910263061523,534.0909652709961
  AudioPlaySdMp3 Deck_A;           // xy=538.0909652709961,463.09087562561035
  AudioAmplifier Amp_AL;           // xy=835.0909423828125,420.0909118652344
  AudioAmplifier Amp_AR;           // xy=840.0909423828125,469.0909118652344
  AudioAmplifier Amp_BR;           // xy=843.0909423828125,583.0909118652344
  AudioAmplifier Amp_BL;           // xy=844.0909423828125,536.0909118652344
  AudioFilterBiquad Filter_BL;     // xy=1089.0909423828125,538.0909118652344
  AudioFilterBiquad Filter_BR;     // xy=1089.0909423828125,584.0909118652344
  AudioFilterBiquad Filter_AL;     // xy=1091.0909423828125,405.0909118652344
  AudioFilterBiquad Filter_AR;     // xy=1094.0909423828125,449.0909118652344
  AudioMixer4 Mixer_Headphone_R;   // xy=1475.0909576416016,428.09089851379395
  AudioMixer4 Mixer_Headphone_L;   // xy=1476.090950012207,346.0909061431885
  AudioMixer4 Mixer_Master_L;      // xy=1481.090950012207,569.0909023284912
  AudioMixer4 Mixer_Master_R;      // xy=1482.090950012207,646.0909023284912
  AudioAmplifier Amp_Master_L;     // xy=1702.090950012207,566.0909328460693
  AudioAmplifier Amp_Master_R;     // xy=1704.0912017822266,636.0909538269043
  AudioAmplifier Amp_Headphone_R;  // xy=1720.090950012207,427.09086990356445
  AudioAmplifier Amp_Headphone_L;  // xy=1726.090705871582,347.09084033966064
  AudioOutputI2S DAC_Master;       // xy=1928.090705871582,606.090892791748
  // AudioOutputI2S2          DAC_Headphone;
  // //xy=1961.0904541015625,397.0908451080322

 private:
  AudioConnection patchCord1{Deck_B, 0, Amp_BL, 0};
  AudioConnection patchCord2{Deck_B, 1, Amp_BR, 0};
  AudioConnection patchCord3{Deck_A, 0, Amp_AL, 0};
  AudioConnection patchCord4{Deck_A, 1, Amp_AR, 0};
  AudioConnection patchCord5{Amp_AL, Filter_AL};
  AudioConnection patchCord6{Amp_AR, Filter_AR};
  AudioConnection patchCord7{Amp_BR, Filter_BR};
  AudioConnection patchCord8{Amp_BL, Filter_BL};
  AudioConnection patchCord9{Filter_BL, 0, Mixer_Headphone_L, 1};
  AudioConnection patchCord10{Filter_BL, 0, Mixer_Master_L, 1};
  AudioConnection patchCord11{Filter_BR, 0, Mixer_Headphone_R, 1};
  AudioConnection patchCord12{Filter_BR, 0, Mixer_Master_R, 1};
  AudioConnection patchCord13{Filter_AL, 0, Mixer_Headphone_L, 0};
  AudioConnection patchCord14{Filter_AL, 0, Mixer_Master_L, 0};
  AudioConnection patchCord15{Filter_AR, 0, Mixer_Headphone_R, 0};
  AudioConnection patchCord16{Filter_AR, 0, Mixer_Master_R, 0};
  AudioConnection patchCord17{Mixer_Headphone_R, Amp_Headphone_R};
  AudioConnection patchCord18{Mixer_Headphone_L, Amp_Headphone_L};
  AudioConnection patchCord19{Mixer_Master_L, Amp_Master_L};
  AudioConnection patchCord20{Mixer_Master_R, Amp_Master_R};
  AudioConnection patchCord21{Amp_Master_L, 0, DAC_Master, 0};
  AudioConnection patchCord22{Amp_Master_R, 0, DAC_Master, 1};
  // AudioConnection          patchCord23{Amp_Headphone_R, 0, DAC_Headphone, 1};
  // AudioConnection          patchCord24{Amp_Headphone_L, 0, DAC_Headphone, 0};
  // GUItool: end automatically generated code
};
}  // namespace audio
}  // namespace apc