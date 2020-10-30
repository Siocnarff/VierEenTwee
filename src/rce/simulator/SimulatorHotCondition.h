#ifndef SIMULATORHOTCONDITION_H
#define SIMULATORHOTCONDITION_H

#include "Simulator.h"
namespace rce
{
    class SimulatorHotCondition : public Simulator {

    public:
        SimulatorHotCondition();

        void SimulateWeather();
    };
}
#endif
