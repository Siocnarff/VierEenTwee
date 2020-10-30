#include "DriverScore.h"

DriverScore(Leaderboard * tl, Leaderboard * dl):Score(tl,dl)
{
	
}

void DriverScore::SetDriverScore(std::string driverName, int Score, std::string TeamName) {
	setscore(Score);

	void setdriverName(driverName);

	void setTeamName(TeamName);
	
	this->Notify();
	
}
