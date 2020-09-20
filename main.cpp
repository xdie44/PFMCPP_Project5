/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 you can safely ignore any warnings about exit-time-destructors.
 if you would like to suppress them, add -Wno-exit-time-destructors to the .replit file 
   with the other warning suppression flags
 */




#include <iostream>
#include "LeakedObjectDetector.h"

/*
 UDT 1:
 */

struct Oscillator
{
    float freq;
    float volume {0.5};
    bool oscCanPlay{true};
    int numHarmonics;
    struct OscWave 
    {
        OscWave();
        ~OscWave();

        float duty = 0.5f;
        float weight = 2.2f;
        int intensity = 3;
        bool play = false;
        char type = 'a';

        void startPlaying(bool isPlaying);
        void makeNoise(float Strength, float weight);
        int changeType(int whichOsc, int newType, int numOsc);

        JUCE_LEAK_DETECTOR(OscWave)
        
    };
    OscWave OscType;

    Oscillator ();
    ~Oscillator();

    float calcHarmonics(float freqIn = 440.0f, int nHarm = 4);
    float freqHalfTone (float freq);
    char changeTimbre (char oscType1 = 'a', char oscType2 = 'b', bool isTheSame = false);
    void oscillatorThisFunction();

    JUCE_LEAK_DETECTOR(Oscillator)
};

Oscillator::Oscillator() : 
                freq(440.0f),
                numHarmonics(4)
{}

Oscillator::~Oscillator()
{
    std::cout << "oscillator is destroyed\n";
}

Oscillator::OscWave::OscWave() : 
                    weight(2.2f), 
                    type('a')
{
    duty = 0.5f;
}

Oscillator::OscWave::~OscWave() 
{
    std::cout << "OscWave Dtor\n";
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

int Oscillator::OscWave::changeType(int whichOsc, int newType, int numOsc)
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

void Oscillator::OscWave::makeNoise (float strength, float weightT)
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

void Oscillator::OscWave::startPlaying(bool isPlaying)
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

void Oscillator::oscillatorThisFunction()
{
    std::cout << "Oscillator frequency (from This Function): " << this->freq << std::endl;
    std::cout << "Oscillator semitoneFreq (from 'This' function): " << this->freqHalfTone(this->freq) << std::endl;
    std::cout << "Oscillator (from 'This' function) ";
    this->OscType.startPlaying(true);
    std::cout << std::endl;
}

struct OscillatorWrapper
{
    OscillatorWrapper(Oscillator* ptr) : pointerToOscillator( ptr ){}
    ~OscillatorWrapper()
    {
        delete pointerToOscillator;
    }
    Oscillator* pointerToOscillator = nullptr;
};

struct OscWaveWrapper
{
    OscWaveWrapper(Oscillator::OscWave* ptr) : pointerToOscWave( ptr ){}
    ~OscWaveWrapper()
    {
        delete pointerToOscWave;
    }
    Oscillator::OscWave* pointerToOscWave = nullptr;
};

/*
 UDT 2:
 */

struct Filter
{
    char filterType;
    float q;
    float centerFreq;
    float slope = 4.5f;
    float resonance = 2.4f;

    Filter();
    ~Filter();

    void filterFreq (float freq, int nHarm);
    void switchOffFilter (bool isFilterActive, int filterT = 3);
    int  nHarm (float freq, float freqMax = 20000.0f);
    void filterThisFunction();

    JUCE_LEAK_DETECTOR(Filter)
};

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

struct FilterWrapper
{
    FilterWrapper(Filter* ptr) : pointerToFilter( ptr ){}
    ~FilterWrapper()
    {
        delete pointerToFilter;
    }
    Filter* pointerToFilter = nullptr;
};

/*
 UDT 3:
 */

struct Lfo
{
    float modFreq;
    float dcOffset;
    float intensity{0.8f};
    bool isActive {true};

    struct LfoType 
    {
        LfoType();
        ~LfoType();

        float lfoDuty, lfoWeight;
        int lfoIntensity = 3;
        bool lfoPlay = false;
        std::string type;

        void startPlaying(bool isPlaying);
        void makeNoise(float strength, float weight);
        int changeType(int whichLfo, int newType, int numLfo);

        JUCE_LEAK_DETECTOR(LfoType)
    };

    LfoType LfoT;

    Lfo();
    ~Lfo();

    bool canSwitchOnLfo (bool isLfoActive = true);
    float changeIntensity (int lfoT, float intensityLfoIn, float intensityLfoOut);
    char changeLfoWave (char waveTypeIn = 'a', char waveTypeOut = 'b');
    void lfoThisFunction();

    JUCE_LEAK_DETECTOR(Lfo)
};

Lfo::LfoType::LfoType() : lfoWeight(1.2f), type("Sine")
{
    lfoDuty = 0.5f;
}

Lfo::LfoType::~LfoType() 
{
    std::cout << "LfoType Dtor\n";
}

Lfo::Lfo()
{
    modFreq = 440.f;
    dcOffset = 0.5f;
}

Lfo::~Lfo()
{
    std::cout << "lfo is destroyed\n";
}

int Lfo::LfoType::changeType(int whichLfo, int newType, int numLfo)
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

void Lfo::LfoType::makeNoise (float strength, float weight)
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

void Lfo::LfoType::startPlaying(bool isPlaying)
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

bool Lfo::canSwitchOnLfo (bool isLfoActive)
{
    return isLfoActive ? false : true;
}

float Lfo::changeIntensity (int lfoT, float intensityLfoIn, float intensityLfoOut)
{
    for (int i = 0; i < lfoT; i++)
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

struct LfoWrapper
{
    LfoWrapper(Lfo* ptr) : pointerToLfo( ptr ){}
    ~LfoWrapper()
    {
        delete pointerToLfo; 
    }
    Lfo* pointerToLfo = nullptr;
};

struct LfoTypeWrapper
{
    LfoTypeWrapper(Lfo::LfoType* ptr) : pointerToLfoType( ptr ){}
    ~LfoTypeWrapper()
    {
        delete pointerToLfoType; 
    }
    Lfo::LfoType* pointerToLfoType = nullptr;
};

/*
 new UDT 4:
 */
struct Synth
{
    Oscillator osc1, osc2, osc3;
    Filter filter1, filter2;

    bool isOn = true;

    ~Synth();

    JUCE_LEAK_DETECTOR(Synth)
};

Synth::~Synth()
{
    osc1.oscCanPlay = false;
    osc2.oscCanPlay = false;
    osc3.oscCanPlay = false;

    filter1.switchOffFilter(true);
    filter2.switchOffFilter(true);

    std::cout << "Synth is destroyed\n";
}

struct SynthWrapper
{
    SynthWrapper(Synth* ptr) : pointerToSynth( ptr ){}
    ~SynthWrapper()
    {
        delete pointerToSynth; 
    }
    Synth* pointerToSynth = nullptr;
};

/*
 new UDT 5:
 */

 struct Modulator
{
    Lfo lfo1, lfo2;
    Filter ModFilter1, ModFilter2;

    bool isOn = false;

    ~Modulator();

    JUCE_LEAK_DETECTOR(Modulator)
};

Modulator::~Modulator()
{
    lfo1.isActive = false;
    lfo2.isActive = false;

    ModFilter1.switchOffFilter(true);
    ModFilter2.switchOffFilter(true);

    std::cout << "Modulator is destroyed\n";
}

struct ModulatorWrapper
{
    ModulatorWrapper(Modulator* ptr) : pointerToModulator( ptr ){}
    ~ModulatorWrapper()
    {
        delete pointerToModulator; 
    }
    Modulator* pointerToModulator = nullptr;
};

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
int main()
{
    std::cout << std::endl;
    Synth synth1, synth2;
    Modulator mainMod, secMod;
    Oscillator mainOsc, secondaryOsc;
    Oscillator::OscWave square, triangle;
    Filter lowPass, highPass;
    Lfo vibrato, tremolo;
    Lfo::LfoType sine, dutyCycle;

    if (synth1.isOn) std::cout << "Synth 1 is On" << std::endl;
    else std::cout << "Synth 1 is Off" << std::endl;

    if (synth2.isOn) std::cout << "Synth 2 is On" << std::endl;
    else std::cout << "Synth 2 is Off" << std::endl;

    if (mainMod.isOn) std::cout << "Main modulator is On" << std::endl;
    else std::cout << "Main modulator is Off" << std::endl;

    if (secMod.isOn) std::cout << "Secondary modulator is On" << std::endl;
    else std::cout << "Secondary modulator is Off" << std::endl;

    std::cout << std::endl;

    mainOsc.freq = 300.0f;
    secondaryOsc.freq = 2 * mainOsc.freq;
    std::cout << "Main Oscillator frequency: " << mainOsc.freq << std::endl;
    mainOsc.oscillatorThisFunction();
    std::cout << "Secondary Oscillator frequency: " << secondaryOsc.freq << std::endl;
    secondaryOsc.oscillatorThisFunction();
    std::cout << std::endl;

    std::cout << "Square ";
    square.changeType(3, 5, 9);
    std::cout << "Triangle oscillator ";
    triangle.startPlaying(false);
    std::cout << "Triangle intensity value: " << triangle.intensity << std::endl;
    std::cout << "Square is making noise? ";
    square.makeNoise(20, 15);
    std::cout << std::endl;

    std::cout << "The low pass filter contains ";
    int nHarmTemp = lowPass.nHarm(400);
    std::cout << " among " << nHarmTemp << " harmonics" << std::endl;
    lowPass.filterThisFunction();
    std::cout << "The high pass slope is: " << highPass.slope << std::endl;
    highPass.filterThisFunction();
    std::cout << std::endl;

    std::cout << "Vibrato intensity is: " << vibrato.intensity << std::endl;
    vibrato.lfoThisFunction();
    std::cout << "Tremolo DC Offset is: " << tremolo.dcOffset << std::endl;
    tremolo.lfoThisFunction();
    std::cout << std::endl;

    std::cout << "Sine Lfo state: ";
    sine.startPlaying(true);
    std::cout << "Is Duty Cycle Lfo making noise? " << std::endl;
    dutyCycle.makeNoise(10.0f, 20.5f);
    std::cout << std::endl;

    std::cout << "good to go!" << std::endl;

    std::cout << std::endl;
}
