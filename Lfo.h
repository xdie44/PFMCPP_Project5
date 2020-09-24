struct Lfo
{
    float modFreq;
    float dcOffset;
    float intensity{0.8f};
    bool isActive {true};

    LfoType LfoT;

    Lfo();
    ~Lfo();

    bool canSwitchOnLfo (bool isLfoActive = true);
    float changeIntensity (int lfoT, float intensityLfoIn, float intensityLfoOut);
    char changeLfoWave (char waveTypeIn = 'a', char waveTypeOut = 'b');
    void lfoThisFunction();

    JUCE_LEAK_DETECTOR(Lfo)
};