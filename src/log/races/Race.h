//
// Created by jo-anne on 2020/10/22.
//

#ifndef LOGISTICS_RACE_H
#define LOGISTICS_RACE_H
#include <string>
#include <enums/TrackComplexity.h>
#include <enums/WeatherConditions.h>

namespace lg {
    class Race {
    private:
        std::string location;
        TrackComplexity complexity;
        bool isInEurope;
        Race *next;
        Race *prev;
        //WeatherConditions raceDayWeather;
        int numLaps;
        TrackComplexity computeTrackComplexity(int comp);
    public:
        Race();

        Race(std::string, int complexity, bool inEU, int laps, Race *next = nullptr, Race *prev = nullptr);

        void setNextRace(Race *);

        void setPrevRace(Race *);

        Race *nextRace();

        Race *prevRace();

        bool isRaceEuropean();

        std::string getLocation();

        TrackComplexity getTrackComplexity();

        /**
         * @details returns a randomly generated weather condition to be gotten for each separate day.
         * If so inclined, one may use only once at the beginning of each race.
         * @return
         */
        WeatherConditions getRaceDayWeather();

        int getNumLaps();
    };
}


#endif //LOGISTICS_RACE_H
