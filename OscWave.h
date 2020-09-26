#pragma once

#include "LeakedObjectDetector.h"

struct OscWave 
{
    OscWave();
    ~OscWave();

    float duty = 0.5f;
    float weight = 2.2f;
    int intensity = 3;
    bool play = false;
    char type = 'a';

    void startPlaying(bool isPlaying);
    void makeNoise(float Strength, float weight);
    int changeType(int whichOsc, int newType, int numOsc);

    JUCE_LEAK_DETECTOR(OscWave)
};
