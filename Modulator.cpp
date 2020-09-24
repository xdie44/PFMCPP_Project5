#include <iostream>
#include "Modulator.h"


Modulator::~Modulator()
{
    lfo1.isActive = false;
    lfo2.isActive = false;

    ModFilter1.switchOffFilter(true);
    ModFilter2.switchOffFilter(true);

    std::cout << "Modulator is destroyed\n";
}
