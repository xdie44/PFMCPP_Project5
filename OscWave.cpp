#include <iostream>
#include "OscWave.h"

OscWave::OscWave() : 
                    weight(2.2f), 
                    type('a')
{
    duty = 0.5f;
}

OscWave::~OscWave() 
{
    std::cout << "OscWave Dtor\n";
}

int OscWave::changeType(int whichOsc, int newType, int numOsc)
{
    for (int i = 1; i < numOsc; i++)
    {
        if (i == newType) 
        {
            std::cout << "oscillator n: " << i << " changed!" << std::endl;
            newType += whichOsc;
        }
    }

    return newType;
}

void OscWave::makeNoise (float strength, float weightT)
{
    if(weightT > strength)
    {
        std::cout << "OscWeight: " << weight << " > " << "strength: " << strength << std::endl;
        std::cout << "Make Noise!\n";
    }
    else 
    {
        std::cout << "No Noise\n";
    }
}

void OscWave::startPlaying(bool isPlaying)
{
    if(isPlaying) 
    {
        std::cout << "Already playing\n";
    }
    else
    {
        play = true;
        std::cout << "now is playing\n";
    }
}