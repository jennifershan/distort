/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DistortMeAudioProcessorEditor::DistortMeAudioProcessorEditor (DistortMeAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    driveLabel.setText ("Drive", dontSendNotification);
    addAndMakeVisible (driveLabel);
    
    addAndMakeVisible (driveSlider);
    driveSlider.setSliderStyle (Slider::Rotary);
    driveSlider.setTextBoxStyle (Slider::NoTextBox, false, 100, 100);
    driveAttachment.reset (new SliderAttachment (p.getState(), "drive", driveSlider));
    
    rangeLabel.setText ("Range", dontSendNotification);
    addAndMakeVisible (rangeLabel);
    
    addAndMakeVisible (rangeSlider);
    rangeSlider.setSliderStyle (Slider::Rotary);
    rangeSlider.setTextBoxStyle (Slider::NoTextBox, false, 100, 100);
    rangeAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment (p.getState(), "range", rangeSlider));
    
    blendLabel.setText ("Blend", dontSendNotification);
    addAndMakeVisible (blendLabel);
    
    addAndMakeVisible (blendSlider);
    blendSlider.setSliderStyle (Slider::Rotary);
    blendSlider.setTextBoxStyle (Slider::NoTextBox, false, 100, 100);
    blendAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment (p.getState(), "blend", blendSlider));
    
    volumeLabel.setText ("Volume", dontSendNotification);
    addAndMakeVisible (volumeLabel);
    
    addAndMakeVisible (volumeSlider);
    volumeSlider.setSliderStyle (Slider::Rotary);
    volumeSlider.setTextBoxStyle (Slider::NoTextBox, false, 100, 100);
    volumeAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment (p.getState(), "volume", volumeSlider));
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 300);
}

DistortMeAudioProcessorEditor::~DistortMeAudioProcessorEditor()
{
}

//==============================================================================
void DistortMeAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    // g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
    
    g.drawText("Drive", getWidth()/5 - 50, getHeight()/2 + 5, 100, Justification::centred, false);
    g.drawText("Range", getWidth()/5 * 2 - 50, getHeight()/2 + 5, 100, Justification::centred, false);
    g.drawText("Blend", getWidth()/5 * 3 - 50, getHeight()/2 + 5, 100, Justification::centred, false);
    g.drawText("Volume", getWidth()/5 * 4 - 50, getHeight()/2 + 5, 100, Justification::centred, false);
}

void DistortMeAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    driveSlider.setBounds((getWidth()/5) - (100/2), (getHeight()/2) - (100/2), 100, 100);
    rangeSlider.setBounds(((getWidth()/5) * 2) - (100/2), (getHeight()/2) - (100/2), 100, 100);
    blendSlider.setBounds(((getWidth()/5) * 3) - (100/2), (getHeight()/2) - (100/2), 100, 100);
    volumeSlider.setBounds(((getWidth()/5) * 4) - (100/2), (getHeight()/2) - (100/2), 100, 100);
}
