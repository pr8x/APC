#pragma once
#include <Audio.h>

#include <array>

namespace apc::audio {

class equalizer {
 public:
  struct filter_bank {
    AudioFilterBiquad* low;
    AudioAmplifier* lowAmp;
    AudioFilterBiquad* mid;
    AudioAmplifier* midAmp;
    AudioFilterBiquad* high;
    AudioAmplifier* highAmp;
  };

  explicit equalizer(std::array<filter_bank, 2> filterBanks);

  void setTreble(float v);

  void setBass(float v);

  void setMid(float v);

 private:
  std::array<filter_bank, 2> _filterBanks;
};

}  // namespace apc::audio