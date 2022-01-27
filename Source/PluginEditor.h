/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class DistortMeAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    DistortMeAudioProcessorEditor (DistortMeAudioProcessor&);
    ~DistortMeAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

private:
    
    Slider driveSlider;
    Slider rangeSlider;
    Slider blendSlider;
    Slider volumeSlider;
    
    Label driveLabel;
    Label rangeLabel;
    Label blendLabel;
    Label volumeLabel;
    
    std::unique_ptr<SliderAttachment> driveAttachment;
    std::unique_ptr<SliderAttachment> rangeAttachment;
    std::unique_ptr<SliderAttachment> blendAttachment;
    std::unique_ptr<SliderAttachment> volumeAttachment;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DistortMeAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DistortMeAudioProcessorEditor)
};
