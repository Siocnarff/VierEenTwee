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

    WeatherConditions randomWC() {
        switch (rand()%3) {
            case 0:
                return Wet;
            case 1:
                return Dry;
            case 2:
                return Rainy;
        }
    }
}

#endif //SRC_WEATHERCONDITIONS_H
