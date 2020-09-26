#pragma once

#include "OscWave.h"

#include "LeakedObjectDetector.h"

struct Oscillator
{
    float freq;
    float volume {0.5};
    bool oscCanPlay{true};
    int numHarmonics;
    
    OscWave oscType;

    Oscillator ();
    ~Oscillator();

    float calcHarmonics(float freqIn = 440.0f, int nHarm = 4);
    float freqHalfTone (float freq);
    char changeTimbre (char oscType1 = 'a', char oscType2 = 'b', bool isTheSame = false);
    void oscillatorThisFunction();

    JUCE_LEAK_DETECTOR(Oscillator)
};
