#include <iostream>
#include "Filter.h"

Filter::Filter () : 
        filterType('a'),
        q(0.4f),
        centerFreq(440.0f)
{}

Filter::~Filter ()
{
    std::cout << "filter is destroyed\n";
}

void Filter::filterFreq (float freq, int nHarm)
{
    int i = 0;
    while (i < nHarm)
    {
        std::cout << "Freq n " << i << " " << freq * i;
        i ++;
    }

}

void Filter::switchOffFilter (bool isFilterActive, int filterT)
{
    int i = 1;
    while (i <= filterT)
    {
        std::cout << "Filter n " << i << " is switched off!\n";
        i++;
    }
    isFilterActive = false;
    filterType = 'o';

}

int Filter::nHarm (float freq, float freqMax)
{
    int i = 1;
    int j = 0;

    while (freq * i < freqMax)
    {
        if (freq * i > 500) 
            j++;

        i++;
    }
    std::cout << j << " harmonics above 500 Hz\n";

    return i;
}

void Filter::filterThisFunction()
{
    std::cout << "The filter contains (from 'This' function) ";
    int nHarmTemp = this->nHarm(400);
    std::cout << " among " << nHarmTemp << " harmonics" << std::endl;
    std::cout << "The filters slope is (from 'This' function): " << this->slope << std::endl;
    std::cout << std::endl;

}