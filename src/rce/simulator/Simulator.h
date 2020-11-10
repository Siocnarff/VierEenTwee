#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <string>
#include <iostream>
#include "../ppl/specialists/Driver.h"

#include "../log/enums/WeatherConditions.h"
#include "../log/enums/TrackComplexity.h"
#include "../pr/Doc.h"
namespace rce
{
    class Simulator
    {
    private:
        ppl::Driver *driver;
        lg::WeatherConditions weather;
        int time;
        lg::TrackComplexity trackDifficulty;
    public:

        void run();

        virtual void SimulateWeather() =0;

        int getTime();

        lg::TrackComplexity getTrackDifficulty();

        lg::WeatherConditions getWeather();

        ppl::Driver *getDriver();

        void setDriver(ppl::Driver *d);

        void setWeather(lg::WeatherConditions w);

        void setTime(int t);

        void setDifficulty(lg::TrackComplexity dif);

    };
}
#endif