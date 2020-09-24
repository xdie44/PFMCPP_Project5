/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */

#include <iostream>
#include "LeakedObjectDetector.h"
#include "Wrappers.h"
#include "Synth.h"
#include "Modulator.h"

int main()
{
    std::cout << std::endl;

    SynthWrapper synth1 ( new Synth ), synth2 (new Synth );
    ModulatorWrapper mainMod ( new Modulator ), secMod ( new Modulator );
    OscillatorWrapper mainOsc ( new Oscillator ), secondaryOsc ( new Oscillator );
    OscWaveWrapper square ( new OscWave ) , triangle ( new OscWave );
    FilterWrapper lowPass ( new Filter ), highPass ( new Filter );
    LfoWrapper vibrato ( new Lfo ), tremolo ( new Lfo );
    LfoTypeWrapper sine ( new LfoType ), dutyCycle ( new LfoType );

    if (synth1.pointerToSynth->isOn) std::cout << "Synth 1 is On" << std::endl;
    else std::cout << "Synth 1 is Off" << std::endl;

    if (synth2.pointerToSynth->isOn) std::cout << "Synth 2 is On" << std::endl;
    else std::cout << "Synth 2 is Off" << std::endl;

    if (mainMod.pointerToModulator->isOn) std::cout << "Main modulator is On" << std::endl;
    else std::cout << "Main modulator is Off" << std::endl;

    if (secMod.pointerToModulator->isOn) std::cout << "Secondary modulator is On" << std::endl;
    else std::cout << "Secondary modulator is Off" << std::endl;

    std::cout << std::endl;

    mainOsc.pointerToOscillator->freq = 300.0f;
    secondaryOsc.pointerToOscillator->freq = 2 * mainOsc.pointerToOscillator->freq;
    std::cout << "Main Oscillator frequency: " << mainOsc.pointerToOscillator->freq << std::endl;
    mainOsc.pointerToOscillator->oscillatorThisFunction();
    std::cout << "Secondary Oscillator frequency: " << secondaryOsc.pointerToOscillator->freq << std::endl;
    secondaryOsc.pointerToOscillator->oscillatorThisFunction();
    std::cout << std::endl;

    std::cout << "Square ";
    square.pointerToOscWave->changeType(3, 5, 9);
    std::cout << "Triangle oscillator ";
    triangle.pointerToOscWave->startPlaying(false);
    std::cout << "Triangle intensity value: " << triangle.pointerToOscWave->intensity << std::endl;
    std::cout << "Square is making noise? ";
    square.pointerToOscWave->makeNoise(20, 15);
    std::cout << std::endl;

    std::cout << "The low pass filter contains ";
    int nHarmTemp = lowPass.pointerToFilter->nHarm(400);
    std::cout << " among " << nHarmTemp << " harmonics" << std::endl;
    lowPass.pointerToFilter->filterThisFunction();
    std::cout << "The high pass slope is: " << highPass.pointerToFilter->slope << std::endl;
    highPass.pointerToFilter->filterThisFunction();
    std::cout << std::endl;

    std::cout << "Vibrato intensity is: " << vibrato.pointerToLfo->intensity << std::endl;
    vibrato.pointerToLfo->lfoThisFunction();
    std::cout << "Tremolo DC Offset is: " << tremolo.pointerToLfo->dcOffset << std::endl;
    tremolo.pointerToLfo->lfoThisFunction();
    std::cout << std::endl;

    std::cout << "Sine Lfo state: ";
    sine.pointerToLfoType->startPlaying(true);
    std::cout << "Is Duty Cycle Lfo making noise? " << std::endl;
    dutyCycle.pointerToLfoType->makeNoise(10.0f, 20.5f);
    std::cout << std::endl;

    std::cout << "good to go!" << std::endl;

    std::cout << std::endl;
}
