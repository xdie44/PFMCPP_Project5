#include <iostream>
#include "LfoType.h"

LfoType::LfoType() : lfoWeight(1.2f), type("Sine")
{
    lfoDuty = 0.5f;
}

LfoType::~LfoType() 
{
    std::cout << "LfoType Dtor\n";
}

int LfoType::changeType(int whichLfo, int newType, int numLfo)
{
    for (int i = 1; i < numLfo; i++)
    {
        if (i == newType) 
        {
            std::cout << "Lfo n: " << i << "changed!";
            newType += whichLfo;
        }
    }
    return newType;
}

void LfoType::makeNoise (float strength, float weight)
{
    if(weight > strength)
    {
        std::cout << "LfoWeight is " << weight << " and strength is " << strength << std::endl;
        std::cout << "so WARNING Lfo is making noise!\n";
    }
    else 
    {
        std::cout << "No Noise\n";
    }
}

void LfoType::startPlaying(bool isPlaying)
{
    if(isPlaying) 
    {
        std::cout << "Lfo already playing\n";
    }
    else
    {
        std::cout << "Now is playing\n";
        isPlaying = true;
    }
}
