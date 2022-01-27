/*
  ==============================================================================

    OscData.cpp
    Created: 7 Jan 2022 8:43:44pm
    Author:  antne

  ==============================================================================
*/

#include "OscData.h"

void OscData::setWaveType(const int choice)
{
    switch (choice)
    {
    case 0:
        initialise([](float x) { return std::sin(x); });
        break;
    case 1:
        initialise([](float x) { return x / juce::MathConstants<float>::pi; });
        break;
    case 2:
        initialise([](float x) { return x < 0.f ? -1.f : 1.f; });
        break;
    default:
        jassertfalse;

    }
}

void OscData::prepareToPlay(juce::dsp::ProcessSpec& spec)
{
    prepare(spec);
}

void OscData::setWaveFrequency(const int midiNoteNumber)
{
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
}

void OscData::getNextAudioBlock(juce::dsp::AudioBlock<float>& block)
{
    process(juce::dsp::ProcessContextReplacing<float>(block));
}
