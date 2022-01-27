/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/AdsrComponent.h"
#include "UI/OscComponent.h"

//==============================================================================
/**
*/
class Synth01AudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    Synth01AudioProcessorEditor (Synth01AudioProcessor&);
    ~Synth01AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Synth01AudioProcessor& audioProcessor;

    OscComponent osc;
    AdsrComponent adsr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Synth01AudioProcessorEditor)
};
