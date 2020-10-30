#include "SimulatorNormalCondition.h"

namespace rce {
    void SimulatorNormalCondition::SimulateWeather() {
        int xp = 0;
        std::cout << "Driver using simulator to train in normal conditions" << std::endl;
        xp = (getTrackDifficulty() / getTime()) * 3;
        getDriver()->setXp(getDriver()->getXp() + xp);
    }

    SimulatorNormalCondition::SimulatorNormalCondition() {

    }
}