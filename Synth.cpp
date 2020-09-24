#pragma once

#include <iostream>
#include "Synth.h"

Synth::~Synth()
{
    osc1.oscCanPlay = false;
    osc2.oscCanPlay = false;
    osc3.oscCanPlay = false;

    filter1.switchOffFilter(true);
    filter2.switchOffFilter(true);

    std::cout << "Synth is destroyed\n";
}