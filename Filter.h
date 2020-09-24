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