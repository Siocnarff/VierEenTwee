//
// Created by jo-anne on 2020/11/02.
//

#ifndef VIEREENTWEE_RANDOMISATION_H
#define VIEREENTWEE_RANDOMISATION_H

#include "WeatherConditions.h"
#include "TrackComplexity.h"
#include "RiskLevel.h"
#include <random>

namespace lg {
    WeatherConditions randomWC() {
        int i = rand() % 3;
        switch (i) {
            case 0:
                return Hot;
            case 1:
                return Normal;
            case 2:
                return Rainy;
        }
    }

    TrackComplexity randomTL()
    {
        switch (rand() % 4)
        {
            case 0:
                return Easy;
            case 1:
                return Average;
            case 2:
                return Difficult;
            case 3:
                return Extreme;
        }
    }

    RiskLevel randomRL()
    {
        switch (rand()%3)
        {
            case 0:
                return Safe;
            case 1:
                return Moderate;
            case 2:
                return Aggressive;
        }
    }
}

#endif //VIEREENTWEE_RANDOMISATION_H
