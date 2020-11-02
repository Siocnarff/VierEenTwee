//
// Created by jo-anne on 2020/10/26.
//

#ifndef SRC_TRACKCOMPLEXITY_H
#define SRC_TRACKCOMPLEXITY_H

namespace lg {
    enum TrackComplexity {
        Easy, Average, Difficult, Extreme
    };

    RiskLevel randomTL() {
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

#endif //SRC_TRACKCOMPLEXITY_H
