#pragma once

#include "LeakedObjectDetector.h"

struct LfoType 
{
    LfoType();
    ~LfoType();

    float lfoDuty, lfoWeight;
    int lfoIntensity = 3;
    bool lfoPlay = false;
    std::string type;

    void startPlaying(bool isPlaying);
    void makeNoise(float strength, float weight);
    int changeType(int whichLfo, int newType, int numLfo);

    JUCE_LEAK_DETECTOR(LfoType)
};
