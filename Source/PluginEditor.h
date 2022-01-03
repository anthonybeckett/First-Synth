/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/AdsrComponent.h"

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
    //Init sliders
    juce::ComboBox oscSelector;

    //Init attachments
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscSelectorAttachment;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Synth01AudioProcessor& audioProcessor;

    AdsrComponent adsr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Synth01AudioProcessorEditor)
};
