#ifndef RACING_DRIVERSCORE_H
#define RACING_DRIVERSCORE_H
#include <string>
#include "Score.h"
namespace racing{
class DriverScore : public racing::Score {


public:
	void SetDriverScore(std::string driverName, int Score, std::string TeamName, bool display);
	//sets the driver score then calls notify to change/update the leaderboard
};
}
#endif
