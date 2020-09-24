struct Synth
{
    Oscillator osc1, osc2, osc3;
    Filter filter1, filter2;

    bool isOn = true;

    ~Synth();

    JUCE_LEAK_DETECTOR(Synth)
};
