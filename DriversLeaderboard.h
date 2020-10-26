#ifndef RACING_DRIVERSLEADERBOARD_H
#define RACING_DRIVERSLEADERBOARD_H
#include <string>
#include "Leaderboard.h"
namespace racing{
class DriversLeaderboard : public racing::Leaderboard {


public:
	void UpdateDriverLeaderBoard(std::string driverName, int Score);
	//used to update the indivitual scores of the driver then displays the output 
};
}
#endif
