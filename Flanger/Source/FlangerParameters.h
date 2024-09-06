#pragma once
#include "JuceHeader.h"
#include "ParameterListeners.h"
#include "FlangerLFO.h"
#include "FlangerInterpolation.h"

class FlangerParameters
{
public:
    // Id's are symbolic names, Names are human-friendly names for GUI.
    // Labels are supplementary, typically used for units of measure.
    static const String minDelayID, minDelayName, minDelayLabel;
    static const float minDelayMin, minDelayMax, minDelayDefault, minDelayStep;
    static const String sweepWidthID, sweepWidthName, sweepWidthLabel;
    static const float sweepWidthMin, sweepWidthMax, sweepWidthDefault, sweepWidthStep;
    static const String depthID, depthName, depthLabel;
    static const float depthMin, depthMax, depthDefault, depthStep;
    static const String feedbackID, feedbackName, feedbackLabel;
    static const float feedbackMin, feedbackMax, feedbackDefault, feedbackStep;
    static const String lfoFreqID, lfoFreqName, lfoFreqLabel;
    static const float lfoFreqMin, lfoFreqMax, lfoFreqDefault, lfoFreqStep;
    static const String stereoID, stereoName, stereoLabel;
    static const int stereoEnumCount, stereoDefault;
    static const String lfoWaveformID, lfoWaveformName, lfoWaveformLabel;
    static const int lfoWaveformEnumCount, lfoWaveformDefault;
    static const String interpTypeID, interpTypeName, interpTypeLabel;
    static const int interpTypeEnumCount, interpTypeDefault;
    static AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

public:
    FlangerParameters(AudioProcessorValueTreeState& vts);
    ~FlangerParameters();

    void detachControls();
    void attachControls(
        Slider& minDelayKnob,
        Slider& sweepWidthKnob,
        Slider& depthKnob,
        Slider& feedbackKnob,
        Slider& lfoFreqKnob,
        ToggleButton& stereoToggle,
        ComboBox& lfoWaveformCombo,
        ComboBox& interpTypeCombo );

    // working parameter values
    float minDelayMs;
    float sweepWidthMs;
    float depth;
    float feedback;
    float lfoFreqHz;
    bool stereoMode;
    FlangerLFO::Waveform lfoWaveform;
    FlangerInterpolation::Type interpolationType;

private:
    // Reference to AudioProcessorValueTreeState object that owns the parameter objects
    AudioProcessorValueTreeState& valueTreeState;

    // Attachment objects link GUI controls to parameters
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> minDelayAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sweepWidthAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> depthAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> feedbackAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> lfoFreqAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> stereoAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> lfoWaveformAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> interpTypeAttachment;

    // Listener objects link parameters to working variables
    FloatListener minDelayListener;
    FloatListener sweepWidthListener;
    FloatListener depthListener;
    FloatListener feedbackListener;
    FloatListener lfoFreqListener;
    BoolListener stereoListener;
    EnumListener<FlangerLFO::Waveform> lfoWaveformListener;
    EnumListener<FlangerInterpolation::Type> interpTypeListener;
};