//
// Created by jo-anne on 2020/10/26.
//

#ifndef SRC_WEATHERCONDITIONS_H
#define SRC_WEATHERCONDITIONS_H

namespace lg {
    enum WeatherConditions {
        Wet, Dry, Rainy
        //Hot, Normal, Rainy
    };

    RiskLevel randomWC() {
        switch (rand()%3) {
            case 0:
                return Safe;
            case 1:
                return Moderate;
            case 2:
                return Aggressive;
        }
    }
}

#endif //SRC_WEATHERCONDITIONS_H
