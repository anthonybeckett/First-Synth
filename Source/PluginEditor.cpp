/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Synth01AudioProcessorEditor::Synth01AudioProcessorEditor (Synth01AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), osc(audioProcessor.getApvts(), "OSC1WAVETYPE"), adsr(audioProcessor.getApvts())
{
    addAndMakeVisible(osc);
    addAndMakeVisible(adsr);

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
    g.fillAll(juce::Colours::black);
}

void Synth01AudioProcessorEditor::resized()
{
    osc.setBounds(10, 10, 100, 30);
    adsr.setBounds(getWidth() / 2, 0, getWidth() / 2, getHeight());
}
