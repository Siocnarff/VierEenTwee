//
// Created by jo-anne on 2020/10/30.
//

#ifndef VIEREENTWEE_LEADERBOARD_H
#define VIEREENTWEE_LEADERBOARD_H

#include <string>

namespace rce {
    class Leaderboard {

    private:
        bool displayLeaderboards;

    public:
        Leaderboard();

        virtual void UpdateLeaderBoard(std::string TN, std::string DriverName, int Score) = 0;

        //virtual void UpdateDriverLeaderBoard(std::string driverName, int Score) = 0;
        virtual void createLeaderboard(std::string DriverName1, std::string DriverName2, int *score) = 0;

        virtual int GetTeamScore(std::string TN) = 0;

        virtual void display() = 0;

        bool getdisplayLeaderboard();

        void setdisplayLeaderboard(bool b);

        //set if the leaderboard should be displayed
    };
}


#endif //VIEREENTWEE_LEADERBOARD_H
