#pragma once
#include <Audio.h>
#include <SD.h>
#include <SPI.h>
#include <SerialFlash.h>
#include <Wire.h>

namespace apc {
namespace audio {
class audio_graph {
 public:
  audio_graph() { Serial.println("Creating audio graph..."); }

  AudioPlayMemory Deck_A;
  AudioPlayMemory Deck_B;
  AudioFilterBiquad Filter_BL;
  AudioFilterBiquad Filter_BR;
  AudioFilterBiquad Filter_AL;
  AudioFilterBiquad Filter_AR;
  AudioMixer4 Mixer_Master_L;
  AudioMixer4 Mixer_Master_R;
  AudioMixer4 Mixer_Headphone_R;
  AudioMixer4 Mixer_Headphone_L;
  AudioAnalyzePeak VU_Master_R;
  AudioAnalyzePeak VU_Master_L;
  AudioOutputI2S2 DAC_Master;
  AudioOutputI2S DAC_Headphones;

 private:
  AudioConnection _patchCord1{Deck_A, 0, Filter_AL, 0};
  AudioConnection _patchCord2{Deck_A, 1, Filter_AR, 0};
  AudioConnection _patchCord3{Deck_B, 0, Filter_BL, 0};
  AudioConnection _patchCord4{Deck_B, 1, Filter_BR, 0};
  AudioConnection _patchCord5{Filter_BL, 0, Mixer_Headphone_L, 1};
  AudioConnection _patchCord6{Filter_BL, 0, Mixer_Master_L, 1};
  AudioConnection _patchCord7{Filter_BR, 0, Mixer_Headphone_R, 1};
  AudioConnection _patchCord8{Filter_BR, 0, Mixer_Master_R, 1};
  AudioConnection _patchCord9{Filter_AL, 0, Mixer_Headphone_L, 0};
  AudioConnection _patchCord10{Filter_AL, 0, Mixer_Master_L, 0};
  AudioConnection _patchCord11{Filter_AR, 0, Mixer_Headphone_R, 0};
  AudioConnection _patchCord12{Filter_AR, 0, Mixer_Master_R, 0};
  AudioConnection _patchCord13{Mixer_Master_L, VU_Master_L};
  AudioConnection _patchCord14{Mixer_Master_L, 0, DAC_Master, 0};
  AudioConnection _patchCord15{Mixer_Master_R, VU_Master_R};
  AudioConnection _patchCord16{Mixer_Master_R, 0, DAC_Master, 1};
  AudioConnection _patchCord17{Mixer_Headphone_R, 0, DAC_Headphones, 1};
  AudioConnection _patchCord18{Mixer_Headphone_L, 0, DAC_Headphones, 0};
};
}  // namespace audio
}  // namespace apc