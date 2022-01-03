/*
  ==============================================================================

    AdsrData.h
    Created: 3 Jan 2022 6:51:28pm
    Author:  antne

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class AdsrData : public juce::ADSR
{
public:
    void updateADSR(const float attack, const float decay, const float sustain, const float release);

private:
    juce::ADSR::Parameters adsrParams;
};