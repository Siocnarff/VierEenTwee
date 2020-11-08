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
        const std::string location;
        TrackComplexity complexity;
        bool isInEurope;
        Race *next;
        Race *previous;
        //WeatherConditions raceDayWeather;
        int numLaps;
        int id;
        static TrackComplexity computeTrackComplexity(int comp);
        std::string output[3];

    public:
        Race();

        Race(std::string, int complexity, bool inEU, int laps, std::string* , Race *next = nullptr, Race *prev = nullptr);

        ~Race();

        void setNextRace(Race *r);

        void setPrevRace(Race *r);

        Race *nextRace();

        Race *prevRace();

        bool isRaceEuropean() const;

        [[nodiscard]] std::string getLocation() const;

        TrackComplexity getTrackComplexity();

        int getTrackID() const;

        /**
         * @details returns a randomly generated weather condition to be gotten for each separate day.
         * If so inclined, one may use only once at the beginning of each race.
         * @return
         */
        static WeatherConditions getRaceDayWeather();

        int getNumLaps() const;

        void printLoc();
    };
}


#endif //LOGISTICS_RACE_H
