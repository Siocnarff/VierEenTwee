#ifndef TEAMLEADERBOARD_H
#define TEAMLEADERBOARD_H
#include <string>
#include "Leaderboard.h"
class TeamLeaderboard : public Leaderboard {


public:
	void UpdateLeaderBoard(string TeamName,string DriverName, int Score);
	//update the team leaderboard and displaces the result
};

#endif
