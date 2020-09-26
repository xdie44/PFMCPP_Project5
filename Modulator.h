#pragma once

#include "Lfo.h"
#include "Filter.h"

struct Modulator
{
    Lfo lfo1, lfo2;
    Filter modFilter1, modFilter2;

    bool isOn = false;

    ~Modulator();

    JUCE_LEAK_DETECTOR(Modulator)
};
