#ifndef RACING_TEAMLEADERBOARD_H
#define RACING_TEAMLEADERBOARD_H
#include <string>
#include "Leaderboard.h"
namespace racing{
class TeamLeaderboard : public racing::Leaderboard {


public:
	void UpdateLeaderBoard(std::string TeamName,std::string DriverName, int Score);
	//update the team leaderboard and displaces the result
};
}
#endif
