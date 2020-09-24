#include "Wrappers.h"

#include "Synth.h"
#include "Modulator.h"

OscillatorWrapper::OscillatorWrapper(Oscillator* ptr) : pointerToOscillator( ptr ){}

OscillatorWrapper::~OscillatorWrapper()
{
    delete pointerToOscillator;
}


//============================================

OscWaveWrapper::OscWaveWrapper(OscWave* ptr) : pointerToOscWave( ptr ){}

OscWaveWrapper::~OscWaveWrapper()
{
    delete pointerToOscWave;
}

//============================================

FilterWrapper::FilterWrapper(Filter* ptr) : pointerToFilter( ptr ){}

FilterWrapper::~FilterWrapper()
{
    delete pointerToFilter;
}

//============================================

LfoWrapper::LfoWrapper(Lfo* ptr) : pointerToLfo( ptr ){}

LfoWrapper::~LfoWrapper()
{
    delete pointerToLfo; 
}

//============================================

LfoTypeWrapper::LfoTypeWrapper(LfoType* ptr) : pointerToLfoType( ptr ){}

LfoTypeWrapper::~LfoTypeWrapper()
{
    delete pointerToLfoType; 
}

//============================================

SynthWrapper::SynthWrapper(Synth* ptr) : pointerToSynth( ptr ){}

SynthWrapper::~SynthWrapper()
{
    delete pointerToSynth; 
}

//============================================

ModulatorWrapper::ModulatorWrapper(Modulator* ptr) : pointerToModulator( ptr ){}

ModulatorWrapper::~ModulatorWrapper()
{
    delete pointerToModulator; 
}
