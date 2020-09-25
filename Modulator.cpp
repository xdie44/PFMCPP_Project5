#include <iostream>
#include "Modulator.h"


Modulator::~Modulator()
{
    lfo1.isActive = false;
    lfo2.isActive = false;

    modFilter1.switchOffFilter(true);
    modFilter2.switchOffFilter(true);

    std::cout << "Modulator is destroyed\n";
}
