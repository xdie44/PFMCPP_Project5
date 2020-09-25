#include <iostream>
#include "Lfo.h"

Lfo::Lfo()
{
    modFreq = 440.f;
    dcOffset = 0.5f;
}

Lfo::~Lfo()
{
    std::cout << "lfo is destroyed\n";
}

bool Lfo::canSwitchOnLfo (bool isLfoActive)
{
    return isLfoActive ? false : true;
}

float Lfo::changeIntensity (int lfoTp, float intensityLfoIn, float intensityLfoOut)
{
    for (int i = 0; i < lfoTp; i++)
    {
        std::cout << "LFO n " << i << " " << intensityLfoOut << "\n";
        intensityLfoOut += intensityLfoIn;
    }
    return intensityLfoOut;
}

char Lfo::changeLfoWave (char waveTypeIn, char waveTypeOut)
{
    return (waveTypeIn != 'o') ? waveTypeOut : waveTypeIn;
}

void Lfo::lfoThisFunction()
{
    std::cout << "Lfo intensity (from 'This' function) is: " << this->intensity << std::endl;
    std::cout << "Lfo DC Offset (from 'This' function) is: " << this->dcOffset << std::endl;
    std::cout << std::endl;

}
