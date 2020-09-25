#include <iostream>
#include "Oscillator.h"

Oscillator::Oscillator() : 
                freq(440.0f),
                numHarmonics(4)
{}

Oscillator::~Oscillator()
{
    std::cout << "oscillator is destroyed\n";
}

float Oscillator::calcHarmonics(float freqIn, int nHarm)
{
    for (int i = 0 ; i < nHarm ; i++)
    {
        freqIn += freqIn + 5;
    }
    return freqIn;
}

float Oscillator::freqHalfTone (float freqTemp)
{
    return 1.1225f * freqTemp;

}

char Oscillator::changeTimbre (char oscType1, char oscType2, bool isTheSame)
{
    return isTheSame ? oscType1 : oscType2;
}

void Oscillator::oscillatorThisFunction()
{
    std::cout << "Oscillator frequency (from This Function): " << this->freq << std::endl;
    std::cout << "Oscillator semitoneFreq (from 'This' function): " << this->freqHalfTone(this->freq) << std::endl;
    std::cout << "Oscillator (from 'This' function) ";
    this->oscType.startPlaying(true);
    std::cout << std::endl;
}
