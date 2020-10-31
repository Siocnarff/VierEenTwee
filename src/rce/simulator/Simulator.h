#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <string>
#include <iostream>
#include "Driver.h"

namespace rce {
    class Simulator {
    private:
        ppl::Driver *driver;
        std::string weather;
        int time;
        int trackDifficulty;
    public:
        // void trainDriver(string weather, ppl::Driver* driver,int trackDifficulty,int time);
        virtual void SimulateWeather() = 0;

        int getTime();

        int getTrackDifficulty();

        std::string getWeather();

        ppl::Driver *getDriver();

        void setDriver(ppl::Driver *d);

        void setWeather(std::string w);

        void setTime(int t);

        void setDifficulty(int dif);
    };
}
#endif