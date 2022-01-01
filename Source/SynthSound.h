/*
  ==============================================================================

    SynthSound.h
    Created: 1 Jan 2022 12:49:38pm
    Author:  Anthony Beckett

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:
    bool appliesToNote(int midiNoteNumber) override { return true; };
    bool appliesToChannel(int midiChannel) override { return true; };
};