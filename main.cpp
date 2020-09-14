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

struct oscillator
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

    oscillator ();
    ~oscillator();

    float calcHarmonics(float freqIn = 440.0f, int nHarm = 4);
    float freqHalfTone (float freq);
    char changeTimbre (char oscType1 = 'a', char oscType2 = 'b', bool isTheSame = false);
    
};

oscillator::oscillator()
{
    freq = 440.0f ;
    int numHarmonics = 4;
}

oscillator::~oscillator()
{
    std::cout << "oscillator is destroyed\n";
}

oscillator::OscWave::OscWave() : weight(2.2f), type("Sine")
{
    duty = 0.5f;
}

oscillator::OscWave::~OscWave() 
{
    std::cout << "OscWave Dtor\n";
}

float oscillator::calcHarmonics(float freqIn, int nHarm)
{
    for (int i = 0 ; i < nHarm ; i++)
    {
        freqIn += freqIn + 5;
    }
    return freqIn;
}

float oscillator::freqHalfTone (float freq)
{
    return 1.1225f*freq;

}

char oscillator::changeTimbre (char oscType1, char oscType2, bool isTheSame)
{
    if (isTheSame) return oscType1;
    return oscType2;
}

int oscillator::OscWave::ChangeType(int whichOsc, int newType, int numOsc)
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
}

void oscillator::OscWave::MakeNoise (float strength, float weight)
{
    if(weight > strength)
    {
        std::cout << "OscWeight: " << weight << " > " << "strength: " << strength << std::endl;
        std::cout << "Make Noise!\n";
    }
    else std::cout << "No Noise\n";
}

void oscillator::OscWave::StartPlaying(bool isPlaying)
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

struct filter
{
    char filterType;
    float q;
    float centerFreq;
    float slope = 4.5f;
    float resonance = 2.4f;

    filter();
    ~filter();

    void FilterFreq (float freq, int nHarm);
    void SwitchOffFilter (bool isFilterActive, int FilterT = 3);
    int  nHarm (float freq, float freqMax = 20000.0f);
};

filter::filter () : 
        filterType('a'),
        q(0.4f),
        centerFreq(440.0f)
{}

filter::~filter ()
{

}

void filter::FilterFreq (float freq, int nHarm)
{
    int i = 0;
    while (i < nHarm)
    {
            std::cout << "Freq n " << i << " " << freq * i;
            i ++;
    }

}

void filter::SwitchOffFilter (bool isFilterActive, int filterT)
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

int filter::nHarm (float freq, float freqMax)
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

struct lfo
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

    lfo();
    ~lfo();

    bool CanSwitchOnLfo (bool isLfoActive = true);
    float ChangeIntensity (int lfoT, float intensityLfoIn, float intensityLfoOut);
    char ChangeLfoWave (char waveTypeIn = 'a', char waveTypeOut = 'b');
};

lfo::LfoType::LfoType() : lfoWeight(1.2f), type("Sine")
{
    lfoDuty = 0.5f;
}

lfo::LfoType::~LfoType() 
{
    std::cout << "LfoType Dtor\n";
}

lfo::lfo()
{
    modFreq = 440.f;
    dcOffset = 0.5f;

}

lfo::~lfo()
{
  
}

int lfo::LfoType::ChangeType(int whichLfo, int newType, int numLfo)
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
}

void lfo::LfoType::MakeNoise (float strength, float weight)
{
    if(weight > strength)
    {
        std::cout << "LfoWeight: " << weight << " > " << "strength: " << strength << std::endl;
        std::cout << "LFO in making noise!\n";
    }
    else std::cout << "No Noise\n";
}

void lfo::LfoType::StartPlaying(bool isPlaying)
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

bool lfo::CanSwitchOnLfo (bool isLfoActive)
{
    if (isLfoActive) return false;
    return true;
}

float lfo::ChangeIntensity (int lfoT, float intensityLfoIn, float intensityLfoOut)
{
    for (int i = 0; i < lfoT; i++)
    {
        std::cout << "LFO n " << i << " " << intensityLfoOut << "\n";
        intensityLfoOut += intensityLfoIn;
    }
    return intensityLfoOut;
}

char lfo::ChangeLfoWave (char waveTypeIn, char waveTypeOut)
{
    if (waveTypeIn != 'o') return waveTypeOut;
    return waveTypeIn;
}

/*
 new UDT 4:
 */

/*
 new UDT 5:
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
int main()
{
    std::cout << "good to go!" << std::endl;
}
