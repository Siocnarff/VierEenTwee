#ifndef SIMULATORNORMALCONDITION_H
#define SIMULATORNORMALCONDITION_H

#include "Simulator.h"
namespace rce {
    class SimulatorNormalCondition : public Simulator {
    public:
        SimulatorNormalCondition();

        void SimulateWeather();
    };
}
#endif
