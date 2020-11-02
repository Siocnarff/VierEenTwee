//
// Created by jo-anne on 2020/10/26.
//

#ifndef SRC_TRACKCOMPLEXITY_H
#define SRC_TRACKCOMPLEXITY_H

#include "random"

namespace lg {
    enum TrackComplexity {
        Easy, Average, Difficult, Extreme
    };
    /*TrackComplexity randomTL() {
        switch (rand()%4) {
            case 0:
                return Easy;
            case 1:
                return Average;
            case 2:
                return Difficult;
            case 3:
                return Extreme;
        }
    }*/
}

#endif //SRC_TRACKCOMPLEXITY_H
