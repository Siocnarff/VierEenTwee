//
// Created by jo-anne on 2020/10/22.
//

#ifndef LOGISTICS_RACE_H
#define LOGISTICS_RACE_H
#include <string>
#include <iostream>
#include <enums/TrackComplexity.h>
#include <enums/WeatherConditions.h>

/**
 * @author Berné
 */
namespace log {
    class Race {
    private:
        std::string location;
        TrackComplexity complexity;
        bool isInEurope;
        int numLaps;
        Race *next;
        Race *prev;
        //WeatherConditions raceDayWeather;
        TrackComplexity computeTrackComplexity(int comp);
    public:
        Race();

        /**
         * @details Constructor taking in variables.
         * @warning Should not be instantiated with only one race. Either both or none is better practice
         * @param next
         * @param prev
         */
        Race(std::string, int complexity, bool inEU, int laps, Race *next = nullptr, Race *prev = nullptr);

        void setNextRace(Race *);

        void setPrevRace(Race *);

        Race *nextRace();

        Race *prevRace();

        bool isRaceEuropean();

        std::string getLocation();

        TrackComplexity getTrackComplexity();

        int getNumLaps();

        /**
         * @details returns a randomly generated weather condition to be gotten for each separate day.
         * If so inclined, one may use only once at the beginning of each race.
         * @return
         */
        WeatherConditions getRaceDayWeather();

//        friend std::ostream& operator<<(std::ostream& os, const Race& rc);
    };
    std::ostream& operator<< (std::ostream& stream, Race race);
}


#endif //LOGISTICS_RACE_H
