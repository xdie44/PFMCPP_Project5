struct Oscillator;
struct OscWave;
struct Filter;
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

    Oscillator::OscWave* pointerToOscWave = nullptr;
};

struct FilterWrapper
{
    FilterWrapper(Filter* ptr);
    ~FilterWrapper();
    
    Filter* pointerToFilter = nullptr;
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