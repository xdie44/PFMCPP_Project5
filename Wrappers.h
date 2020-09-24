struct Oscillator;
struct OscWave;
struct Filter;
struct Lfo;
struct LfoType;
struct Synth;
struct Modulator;


struct OscillatorWrapper
{
    OscillatorWrapper(Oscillator* ptr);
    ~OscillatorWrapper();
    
    Oscillator* pointerToOscillator = nullptr;
};

struct OscWaveWrapper
{
    OscWaveWrapper(OscWave* ptr);
    ~OscWaveWrapper();

    OscWave* pointerToOscWave = nullptr;
};

struct FilterWrapper
{
    FilterWrapper(Filter* ptr);
    ~FilterWrapper();
    
    Filter* pointerToFilter = nullptr;
};

struct LfoWrapper
{
    LfoWrapper(Lfo* ptr);
    ~LfoWrapper();
    
    Lfo* pointerToLfo = nullptr;
};

struct LfoTypeWrapper
{
    LfoTypeWrapper(LfoType* ptr);
    ~LfoTypeWrapper();
    
    LfoType* pointerToLfoType = nullptr;
};

struct SynthWrapper
{
    SynthWrapper(Synth* ptr);
    ~SynthWrapper();
    
    Synth* pointerToSynth = nullptr;
};

struct ModulatorWrapper
{
    ModulatorWrapper(Modulator* ptr);
    ~ModulatorWrapper();
    
    Modulator* pointerToModulator = nullptr;
};
