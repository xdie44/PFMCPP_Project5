#pragma once

#include "Lfo.h"
#include "Filter.h"

struct Modulator
{
    Lfo lfo1, lfo2;
    Filter ModFilter1, ModFilter2;

    bool isOn = false;

    ~Modulator();

    JUCE_LEAK_DETECTOR(Modulator)
};
