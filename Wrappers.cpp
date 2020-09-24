#include "Oscillator.h"
#include "OscWave.h"
#include "Filter.h"
#include "Wrappers.h"
#include "Synth.h"
#include "Modulator.h"

OscillatorWrapper::OscillatorWrapper(Oscillator* ptr) : pointerToOscillator( ptr ){}

OscillatorWrapper::~OscillatorWrapper()
{
    delete pointerToOscillator;
}

Oscillator* pointerToOscillator = nullptr;

//============================================

OscWaveWrapper::OscWaveWrapper(OscWave* ptr) : pointerToOscWave( ptr ){}

OscWaveWrapper::~OscWaveWrapper()
{
    delete pointerToOscWave;
}

OscWave* pointerToOscWave = nullptr;

//============================================

FilterWrapper::FilterWrapper(Filter* ptr) : pointerToFilter( ptr ){}

FilterWrapper::~FilterWrapper()
{
    delete pointerToFilter;
}

Filter* pointerToFilter = nullptr;

//============================================

SynthWrapper::SynthWrapper(Synth* ptr) : pointerToSynth( ptr ){}

SynthWrapper::~SynthWrapper()
{
    delete pointerToSynth; 
}

Synth* pointerToSynth = nullptr;

//============================================

ModulatorWrapper::ModulatorWrapper(Modulator* ptr) : pointerToModulator( ptr ){}

ModulatorWrapper::~ModulatorWrapper()
{
    delete pointerToModulator; 
}

Modulator* pointerToModulator = nullptr;
