#pragma once
#include <Audio.h>
#include <SPI.h>
#include <SerialFlash.h>
#include <Wire.h>
#include <config.h>
#include <logger.h>
#include <play_sd_mp3.h>

namespace apc::audio {

class audio_graph {
 public:
  audio_graph() {
    APC_LOG_INFO("Creating audio graph...");
    APC_LOG_DEBUG("Audio memory blocks: %d", AudioMemoryBlocks);
    AudioMemory(AudioMemoryBlocks);
  }

  // GUItool: begin automatically generated code
  AudioPlaySdMp3 Deck_A;             // xy=259.09095001220703,358.0908451080322
  AudioPlaySdMp3 Deck_B;             // xy=261.99999618530273,677.0910243988037
  AudioFilterBiquad Filter_BR_Mid;   // xy=661.9999656677246,745.0910453796387
  AudioFilterBiquad Filter_AL_Low;   // xy=665.0909042358398,211.09084796905518
  AudioFilterBiquad Filter_BL_Low;   // xy=663.9999656677246,550.0909881591797
  AudioFilterBiquad Filter_AL_Mid;   // xy=666.0909652709961,258.09084701538086
  AudioFilterBiquad Filter_AL_High;  // xy=666.0908966064453,306.090877532959
  AudioFilterBiquad Filter_BL_Mid;   // xy=665.0000267028809,597.090986251831
  AudioFilterBiquad Filter_BL_High;  // xy=664.9999504089355,645.0910186767578
  AudioFilterBiquad Filter_BR_Low;   // xy=664.9999656677246,701.0910472869873
  AudioFilterBiquad Filter_BR_High;  // xy=667.9999656677246,791.0911064147949
  AudioFilterBiquad Filter_AR_Low;   // xy=672.0909042358398,373.0909376144409
  AudioFilterBiquad Filter_AR_Mid;   // xy=673.0909652709961,420.0909366607666
  AudioFilterBiquad Filter_AR_High;  // xy=673.0908966064453,468.0909671783447
  AudioAmplifier Amp_BL_Low;         // xy=852.0000190734863,549.0910263061523
  AudioAmplifier Amp_AL_Mid;         // xy=856.0909576416016,252.09089279174805
  AudioAmplifier Amp_BL_Mid;         // xy=855.0000190734863,591.090986251831
  AudioAmplifier Amp_AL_High;        // xy=858.0909576416016,293.0909080505371
  AudioAmplifier Amp_BL_High;        // xy=857.0000114440918,632.0910491943359
  AudioAmplifier Amp_AL_Low;         // xy=859.0909576416016,210.0908784866333
  AudioAmplifier Amp_BR_Mid;         // xy=861.0000114440918,746.0910620689392
  AudioAmplifier Amp_AR_Mid;         // xy=863.0909576416016,414.0909824371338
  AudioAmplifier Amp_BR_High;        // xy=863.0000114440918,787.0910773277283
  AudioAmplifier Amp_BR_Low;         // xy=864.0000190734863,701.0910844802856
  AudioAmplifier Amp_AR_High;        // xy=865.0909576416016,455.09099769592285
  AudioAmplifier Amp_AR_Low;         // xy=866.0909576416016,372.09096813201904
  AudioMixer4 Mixer_AL_EQ;           // xy=1081.0908966064453,266.090877532959
  AudioMixer4 Mixer_BL_EQ;           // xy=1079.9998931884766,605.0910263061523
  AudioMixer4 Mixer_AR_EQ;           // xy=1082.090835571289,399.09093856811523
  AudioMixer4 Mixer_BR_EQ;           // xy=1081.9998970031738,735.0910835266113
  AudioAmplifier Amp_AR;             // xy=1263.090955734253,392.09087562561035
  AudioAmplifier Amp_AL;             // xy=1264.0909576416016,267.0908012390137
  AudioAmplifier Amp_BL;             // xy=1263.0000114440918,606.0909423828125
  AudioAmplifier Amp_BR;             // xy=1265.0000190734863,690.0909624099731
  AudioMixer4 Mixer_Master_L;        // xy=1576.090950012207,611.0909042358398
  AudioMixer4 Mixer_Master_R;        // xy=1577.090950012207,688.0909042358398
  AudioMixer4 Mixer_Headphone_R;     // xy=1587.0909576416016,473.0908393859863
  AudioMixer4 Mixer_Headphone_L;     // xy=1588.090950012207,391.09084701538086
  AudioAmplifier Amp_Master_R;       // xy=1797.0910720825195,670.0909023284912
  AudioAmplifier Amp_Master_L;       // xy=1799.090950012207,622.0909042358398
  AudioAmplifier Amp_Headphone_L;    // xy=1827.0905838012695,394.0907726287842
  AudioAmplifier Amp_Headphone_R;    // xy=1827.0908279418945,441.0908145904541
  AudioOutputI2S DAC_Master;         // xy=1992.0906982421875,642.0909023284912
  AudioOutputI2S2 DAC_Headphone;     // xy=2050.0904541015625,418.09075355529785

 private:
  AudioConnection patchCord1{Deck_A, 0, Filter_AL_Low, 0};
  AudioConnection patchCord2{Deck_A, 0, Filter_AL_Mid, 0};
  AudioConnection patchCord3{Deck_A, 0, Filter_AL_High, 0};
  AudioConnection patchCord4{Deck_A, 1, Filter_AR_Low, 0};
  AudioConnection patchCord5{Deck_A, 1, Filter_AR_Mid, 0};
  AudioConnection patchCord6{Deck_A, 1, Filter_AR_High, 0};
  AudioConnection patchCord7{Deck_B, 0, Filter_BL_Low, 0};
  AudioConnection patchCord8{Deck_B, 0, Filter_BL_Mid, 0};
  AudioConnection patchCord9{Deck_B, 0, Filter_BL_High, 0};
  AudioConnection patchCord10{Deck_B, 1, Filter_BR_Low, 0};
  AudioConnection patchCord11{Deck_B, 1, Filter_BR_Mid, 0};
  AudioConnection patchCord12{Deck_B, 1, Filter_BR_High, 0};
  AudioConnection patchCord13{Filter_BR_Mid, Amp_BR_Mid};
  AudioConnection patchCord14{Filter_AL_Low, Amp_AL_Low};
  AudioConnection patchCord15{Filter_BL_Low, Amp_BL_Low};
  AudioConnection patchCord16{Filter_AL_Mid, Amp_AL_Mid};
  AudioConnection patchCord17{Filter_AL_High, Amp_AL_High};
  AudioConnection patchCord18{Filter_BL_Mid, Amp_BL_Mid};
  AudioConnection patchCord19{Filter_BL_High, Amp_BL_High};
  AudioConnection patchCord20{Filter_BR_Low, Amp_BR_Low};
  AudioConnection patchCord21{Filter_BR_High, Amp_BR_High};
  AudioConnection patchCord22{Filter_AR_Low, Amp_AR_Low};
  AudioConnection patchCord23{Filter_AR_Mid, Amp_AR_Mid};
  AudioConnection patchCord24{Filter_AR_High, Amp_AR_High};
  AudioConnection patchCord25{Amp_BL_Low, 0, Mixer_BL_EQ, 0};
  AudioConnection patchCord26{Amp_AL_Mid, 0, Mixer_AL_EQ, 1};
  AudioConnection patchCord27{Amp_BL_Mid, 0, Mixer_BL_EQ, 1};
  AudioConnection patchCord28{Amp_AL_High, 0, Mixer_AL_EQ, 2};
  AudioConnection patchCord29{Amp_BL_High, 0, Mixer_BL_EQ, 2};
  AudioConnection patchCord30{Amp_AL_Low, 0, Mixer_AL_EQ, 0};
  AudioConnection patchCord31{Amp_BR_Mid, 0, Mixer_BR_EQ, 1};
  AudioConnection patchCord32{Amp_AR_Mid, 0, Mixer_AR_EQ, 1};
  AudioConnection patchCord33{Amp_BR_High, 0, Mixer_BR_EQ, 2};
  AudioConnection patchCord34{Amp_BR_Low, 0, Mixer_BR_EQ, 0};
  AudioConnection patchCord35{Amp_AR_High, 0, Mixer_AR_EQ, 2};
  AudioConnection patchCord36{Amp_AR_Low, 0, Mixer_AR_EQ, 0};
  AudioConnection patchCord37{Mixer_AL_EQ, Amp_AL};
  AudioConnection patchCord38{Mixer_BL_EQ, Amp_BL};
  AudioConnection patchCord39{Mixer_AR_EQ, Amp_AR};
  AudioConnection patchCord40{Mixer_BR_EQ, Amp_BR};
  AudioConnection patchCord41{Amp_AR, 0, Mixer_Headphone_R, 0};
  AudioConnection patchCord42{Amp_AR, 0, Mixer_Master_R, 0};
  AudioConnection patchCord43{Amp_AL, 0, Mixer_Headphone_L, 0};
  AudioConnection patchCord44{Amp_AL, 0, Mixer_Master_L, 0};
  AudioConnection patchCord45{Amp_BL, 0, Mixer_Headphone_L, 1};
  AudioConnection patchCord46{Amp_BL, 0, Mixer_Master_L, 1};
  AudioConnection patchCord47{Amp_BR, 0, Mixer_Headphone_R, 1};
  AudioConnection patchCord48{Amp_BR, 0, Mixer_Master_R, 1};
  AudioConnection patchCord49{Mixer_Master_L, Amp_Master_L};
  AudioConnection patchCord50{Mixer_Master_R, Amp_Master_R};
  AudioConnection patchCord51{Mixer_Headphone_R, Amp_Headphone_R};
  AudioConnection patchCord52{Mixer_Headphone_L, Amp_Headphone_L};
  AudioConnection patchCord53{Amp_Master_R, 0, DAC_Master, 1};
  AudioConnection patchCord54{Amp_Master_L, 0, DAC_Master, 0};
  // AudioConnection          patchCord55(Amp_Headphone_L, 0, DAC_Headphone, 0);
  // AudioConnection          patchCord56(Amp_Headphone_R, 0, DAC_Headphone, 1);
  // GUItool: end automatically generated code
};

}  // namespace apc::audio