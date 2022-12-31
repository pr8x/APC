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

  AudioPlayMemory Deck_A;         // xy=68.00569152832031,405.0056571960449
  AudioPlayMemory Deck_B;         // xy=73.00569152832031,453.0056571960449
  AudioAmplifier Amp_AL;          // xy=319.00566482543945,353.1874942779541
  AudioAmplifier Amp_AR;          // xy=324.00567626953125,402.1875
  AudioAmplifier Amp_BR;          // xy=327.00567626953125,516.1875
  AudioAmplifier Amp_BL;          // xy=328.00567626953125,469.1875
  AudioFilterBiquad Filter_BL;    // xy=573.9999809265137,471.99999141693115
  AudioFilterBiquad Filter_BR;    // xy=573.9999656677246,517.9999837875366
  AudioFilterBiquad Filter_AL;    // xy=575.9999923706055,338.0000009536743
  AudioFilterBiquad Filter_AR;    // xy=578.9999885559082,382.00000286102295
  AudioMixer4 Mixer_Master_L;     // xy=1127.9999732971191,578.9999761581421
  AudioMixer4 Mixer_Master_R;     // xy=1129.0000190734863,655.0000019073486
  AudioMixer4 Mixer_Headphone_R;  // xy=1145.000015258789,371.99999713897705
  AudioMixer4 Mixer_Headphone_L;  // xy=1146.000015258789,289.9999952316284
  AudioAnalyzePeak VU_Master_R;   // xy=1343.0000114440918,704.0000009536743
  AudioAnalyzePeak VU_Master_L;   // xy=1347.0000114440918,488.99999713897705
  //AudioOutputI2S2 DAC_Headphone;  // xy=1544.0058631896973,342.00558948516846
  AudioOutputI2S DAC_Master;      // xy=1559.0057525634766,616.0056571960449

 private:
  AudioConnection _patchCord1{Deck_A, DAC_Master};
  AudioConnection _patchCord2{Deck_A, Amp_AR};
  AudioConnection _patchCord3{Deck_B, Amp_BL};
  AudioConnection _patchCord4{Deck_B, Amp_BR};
  AudioConnection _patchCord5{Amp_AL, 0, Mixer_Master_L, 0};
  AudioConnection _patchCord6{Amp_AR, 0, Mixer_Master_R, 0};
  AudioConnection _patchCord7{Amp_BR, 0, Mixer_Master_R, 1};
  AudioConnection _patchCord8{Amp_BL, 0, Mixer_Master_L, 1};
  AudioConnection _patchCord9{Filter_BL, 0, Mixer_Headphone_L, 1};
  AudioConnection _patchCord10{Filter_BL, 0, Mixer_Master_L, 1};
  AudioConnection _patchCord11{Filter_BR, 0, Mixer_Headphone_R, 1};
  AudioConnection _patchCord12{Filter_BR, 0, Mixer_Master_R, 1};
  AudioConnection _patchCord13{Filter_AL, 0, Mixer_Headphone_L, 0};
  AudioConnection _patchCord14{Filter_AL, 0, Mixer_Master_L, 0};
  AudioConnection _patchCord15{Filter_AR, 0, Mixer_Headphone_R, 0};
  AudioConnection _patchCord16{Filter_AR, 0, Mixer_Master_R, 0};
  AudioConnection _patchCord17{Mixer_Master_L, VU_Master_L};
  AudioConnection _patchCord18{Mixer_Master_L, 0, DAC_Master, 0};
  AudioConnection _patchCord19{Mixer_Master_R, VU_Master_R};
  AudioConnection _patchCord20{Mixer_Master_R, 0, DAC_Master, 1};
  // AudioConnection _patchCord21{Mixer_Headphone_R, 0, DAC_Headphone, 1};
  // AudioConnection _patchCord22{Mixer_Headphone_L, 0, DAC_Headphone, 0};
};
}  // namespace audio
}  // namespace apc