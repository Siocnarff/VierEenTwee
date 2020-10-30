#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <string>
#include <iostream>
#include "../ppl/specialists/Driver.h"

#include "../log/enums/WeatherConditions.h"
#include "../log/enums/TrackComplexity.h"
namespace rce
{
    class Simulator
    {
    private:
        ppl::Driver *driver;
        log::WeatherConditions weather;
        int time;
        log::TrackComplexity trackDifficulty;
    public:
        virtual void SimulateWeather() = 0;

        int getTime();

        log::TrackComplexity getTrackDifficulty();

        log::WeatherConditions getWeather();

        ppl::Driver *getDriver();

        void setDriver(ppl::Driver *d);

        void setWeather(log::WeatherConditions w);

        void setTime(int t);

        void setDifficulty(log::TrackComplexity dif);
    };
}
#endif