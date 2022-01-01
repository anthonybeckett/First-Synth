/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Synth01AudioProcessorEditor::Synth01AudioProcessorEditor (Synth01AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

    attackSliderAttachment = std::make_unique<SliderAttachment>(audioProcessor.getApvts(), "ATTACK", attackSlider);
    decaySliderAttachment = std::make_unique<SliderAttachment>(audioProcessor.getApvts(), "DECAY", decaySlider);
    sustainSliderAttachment = std::make_unique<SliderAttachment>(audioProcessor.getApvts(), "SUSTAIN", sustainSlider);
    releaseSliderAttachment = std::make_unique<SliderAttachment>(audioProcessor.getApvts(), "RELEASE", releaseSlider);

    oscSelectorAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.getApvts(), "OSC", oscSelector);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

Synth01AudioProcessorEditor::~Synth01AudioProcessorEditor()
{
}

//==============================================================================
void Synth01AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void Synth01AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
