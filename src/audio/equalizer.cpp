#include <audio/equalizer.h>
#include <logger.h>

apc::audio::equalizer::equalizer(std::array<filter_bank, 2> filterBanks)
    : _filterBanks(filterBanks) {
  _filterBanks[0].low->setBandpass(0, 80, 0.4f);
  _filterBanks[0].low->setBandpass(0, 80, 0.4f);
  _filterBanks[1].mid->setBandpass(0, 1200, 0.4f);
  _filterBanks[1].mid->setBandpass(0, 1200, 0.4f);
  _filterBanks[2].high->setBandpass(0, 10000, 0.4f);
  _filterBanks[2].high->setBandpass(0, 10000, 0.4f);
}

void apc::audio::equalizer::setBass(float v) {
  _filterBanks[0].lowAmp->gain(v);
  _filterBanks[1].lowAmp->gain(v);
}

void apc::audio::equalizer::setMid(float v) {
  _filterBanks[0].midAmp->gain(v);
  _filterBanks[1].midAmp->gain(v);
}

void apc::audio::equalizer::setTreble(float v) {
  _filterBanks[0].highAmp->gain(v);
  _filterBanks[1].highAmp->gain(v);
}
