/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12
 Create a branch named Part1
Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 
Since you didn't do Project 3:
write 3 UDTs below (where it asks for Copied UDTs) that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
 
 4) add 2 new UDTs that use only the types you copied above as member variables.
 
 5) Add destructors to these 2 new types that do something.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) use at least 2 instances of each of your UDTs in main. 
        add some std::cout statements in main() that use your UDT's member variables.
 
 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
If you need inspiration for what to write, take a look at previously approved student projects in the Slack Workspace channel for this project part.
 */
#include <iostream>

/*
 UDT 1:
 */

struct Oscillator
{
    float freq;
    bool oscCanPlay{true};
    float volume {0.5f};
    int numHarmonics;
    struct OscWave 
    {
        OscWave();
        ~OscWave();

        float duty, weight;
        int intensity = 3;
        bool play = false;
        std::string type;

        void StartPlaying(bool isPlaying);
        void MakeNoise(float Strength, float weight);
        int ChangeType(int whichOsc, int newType, int numOsc);
        
    };
    OscWave OscType;

    Oscillator ();
    ~Oscillator();

    float calcHarmonics(float freqIn = 440.0f, int nHarm = 4);
    float freqHalfTone (float freq);
    char changeTimbre (char oscType1 = 'a', char oscType2 = 'b', bool isTheSame = false);
    
};

Oscillator::Oscillator()
{
    freq = 440.0f ;
    int numHarmonics = 4;
}

Oscillator::~Oscillator()
{
    std::cout << "oscillator is destroyed\n";
}

Oscillator::OscWave::OscWave() : weight(2.2f), type("Sine")
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

float Oscillator::freqHalfTone (float freq)
{
    return 1.1225f*freq;

}

char Oscillator::changeTimbre (char oscType1, char oscType2, bool isTheSame)
{
    if (isTheSame) return oscType1;
    return oscType2;
}

int Oscillator::OscWave::ChangeType(int whichOsc, int newType, int numOsc)
{
    for (int i = 1; i < numOsc; i++)
    {
        if (i == newType) 
        {
            std::cout << "oscillator n: " << i << "changed!";
            newType += whichOsc;
        }
    i++;
    }

    return newType;
}

void Oscillator::OscWave::MakeNoise (float strength, float weight)
{
    if(weight > strength)
    {
        std::cout << "OscWeight: " << weight << " > " << "strength: " << strength << std::endl;
        std::cout << "Make Noise!\n";
    }
    else std::cout << "No Noise\n";
}

void Oscillator::OscWave::StartPlaying(bool isPlaying)
{
    if(isPlaying) 
    {
        std::cout << "Already playing\n.";
    }
    else
    {
        play = true;
        std::cout << "Now is playing\n.";
    }
}

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

    void FilterFreq (float freq, int nHarm);
    void SwitchOffFilter (bool isFilterActive, int FilterT = 3);
    int  nHarm (float freq, float freqMax = 20000.0f);
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

void Filter::FilterFreq (float freq, int nHarm)
{
    int i = 0;
    while (i < nHarm)
    {
            std::cout << "Freq n " << i << " " << freq * i;
            i ++;
    }

}

void Filter::SwitchOffFilter (bool isFilterActive, int filterT)
{
    int i = 0;
    while (isFilterActive)
        {
            if (filterT == i) isFilterActive = false;
             std::cout << "Filter n " << i << " is not active!\n";
            i++;
        }
    filterType = 'o';

}

int Filter::nHarm (float freq, float freqMax)
{
    int i = 1;

    while (freq * i < freqMax)
    {
        std::cout << "Harmonic n " << i << " - " << freq * i << "\n";
        i++;
    }
    std::cout << "There are " << i << " harmonics\n";

    return i;
}

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

        void StartPlaying(bool isPlaying);
        void MakeNoise(float strength, float weight);
        int ChangeType(int whichLfo, int newType, int numLfo);
        
    };

    LfoType LfoT;

    Lfo();
    ~Lfo();

    bool CanSwitchOnLfo (bool isLfoActive = true);
    float ChangeIntensity (int lfoT, float intensityLfoIn, float intensityLfoOut);
    char ChangeLfoWave (char waveTypeIn = 'a', char waveTypeOut = 'b');
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

int Lfo::LfoType::ChangeType(int whichLfo, int newType, int numLfo)
{
    for (int i = 1; i < numLfo; i++)
    {
        if (i == newType) 
        {
            std::cout << "Lfo n: " << i << "changed!";
            newType += whichLfo;
        }
    i++;
    }
    return newType;
}

void Lfo::LfoType::MakeNoise (float strength, float weight)
{
    if(weight > strength)
    {
        std::cout << "LfoWeight: " << weight << " > " << "strength: " << strength << std::endl;
        std::cout << "LFO in making noise!\n";
    }
    else std::cout << "No Noise\n";
}

void Lfo::LfoType::StartPlaying(bool isPlaying)
{
    if(isPlaying) 
    {
        std::cout << "Lfo already playing\n.";
    }
    else
    {
        std::cout << "Now is playing\n.";
        isPlaying = true;
    }
}

bool Lfo::CanSwitchOnLfo (bool isLfoActive)
{
    if (isLfoActive) return false;
    return true;
}

float Lfo::ChangeIntensity (int lfoT, float intensityLfoIn, float intensityLfoOut)
{
    for (int i = 0; i < lfoT; i++)
    {
        std::cout << "LFO n " << i << " " << intensityLfoOut << "\n";
        intensityLfoOut += intensityLfoIn;
    }
    return intensityLfoOut;
}

char Lfo::ChangeLfoWave (char waveTypeIn, char waveTypeOut)
{
    if (waveTypeIn != 'o') return waveTypeOut;
    return waveTypeIn;
}

/*
 new UDT 4:
 */
struct Synth
{
    Oscillator osc1, osc2, osc3;
    Filter filter1, filter2;

    ~Synth();
};

Synth::~Synth()
{
    osc1.oscCanPlay = false;
    osc2.oscCanPlay = false;
    osc3.oscCanPlay = false;

    filter1.SwitchOffFilter(true);
    filter2.SwitchOffFilter(true);

    std::cout << "Synth is destroyed\n";
}
/*
 new UDT 5:
 */
 struct Modulator
{
    Lfo lfo1, lfo2;
    Filter ModFilter1, ModFilter2;

    ~Modulator();
};

Modulator::~Modulator()
{
    lfo1.isActive = false;
    lfo2.isActive = false;

    ModFilter1.SwitchOffFilter(true);
    ModFilter2.SwitchOffFilter(true);

    std::cout << "Modulator is destroyed\n";
}



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
    Oscillator mainOsc, secondaryOsc;
    Oscillator::OscWave square, triangle;
    Filter lowPass, highPass;
    Lfo vibrato, tremolo;
    Lfo::LfoType sine, dutyCycle;

    mainOsc.freq = 300.0f;
    secondaryOsc.freq = 2 * mainOsc.freq;
    std::cout << "Main Oscillator frequency: " << mainOsc.freq << std::endl;
    std::cout << "Secondary Oscillator frequency: " << secondaryOsc.freq << std::endl;
    std::cout << std::endl;

    square.ChangeType(3, 5, 9);
    triangle.StartPlaying(true);
    std::cout << "Triangle intensity value: " << triangle.intensity << std::endl;
    std::cout << "Square is making noise? ";
    square.MakeNoise(20, 15);
    std::cout << std::endl;

    std::cout << "The low pass filter contains " << lowPass.nHarm(400) << " harmonics" << std::endl;
    std::cout << "The high pass slope is: " << highPass.slope << std::endl;
    std::cout << std::endl;

    std::cout << "Vibrato intensity is: " << vibrato.intensity << std::endl;
    std::cout << "Tremolo DC Offset is: " << vibrato.dcOffset << std::endl;
    std::cout << std::endl;

    std::cout << "Sine Lfo state: " << std::endl;
    sine.StartPlaying(true);
    std::cout << "If Duty Cycle Lfo making noise? " << std::endl;
    dutyCycle.MakeNoise(10.0f, 20.5f);
    std::cout << std::endl;

    std::cout << "good to go!" << std::endl;
}
