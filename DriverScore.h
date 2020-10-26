#ifndef DRIVERSCORE_H
#define DRIVERSCORE_H
#include <string>
class DriverScore : public Score {


public:
	void SetDriverScore(string driverName, int Score, string TeamName, bool display);
	//sets the driver score then calls notify to change/update the leaderboard
};

#endif
