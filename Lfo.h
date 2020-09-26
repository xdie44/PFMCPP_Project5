#pragma once

#include "LeakedObjectDetector.h"

#include "LfoType.h"

struct Lfo
{
    float modFreq;
    float dcOffset;
    float intensity{0.8f};
    bool isActive {true};

    LfoType lfoT;

    Lfo();
    ~Lfo();

    bool canSwitchOnLfo (bool isLfoActive = true);
    float changeIntensity (int lfoTp, float intensityLfoIn, float intensityLfoOut);
    char changeLfoWave (char waveTypeIn = 'a', char waveTypeOut = 'b');
    void lfoThisFunction();

    JUCE_LEAK_DETECTOR(Lfo)
};
