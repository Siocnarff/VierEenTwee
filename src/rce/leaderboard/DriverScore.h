#ifndef RACING_DRIVERSCORE_H
#define RACING_DRIVERSCORE_H

#include <string>
#include "Score.h"

namespace rce {

    class DriverScore : public Score {

    public:
        DriverScore(Leaderboard *tl, Leaderboard *dl);

        void SetDriverScore(std::string driverName, int Score, std::string TeamName, bool display);
        //sets the driver score then calls notify to change/update the leaderboard
    };
}
#endif
