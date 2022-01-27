/*
  ==============================================================================

    OscData.h
    Created: 7 Jan 2022 8:43:44pm
    Author:  antne

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class OscData : public juce::dsp::Oscillator<float>
{
public:
    void setWaveType(const int choice);
    void prepareToPlay(juce::dsp::ProcessSpec& spec);
    void setWaveFrequency(const int midiNoteNumber);
    void getNextAudioBlock(juce::dsp::AudioBlock<float>& block);

private:

};