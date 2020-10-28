#include "Score.h"
Score::Score(Leaderboard* driverlead,Leaderboard* Teamlead)
{
	this->driverlead = driverlead;
	this->Teamlead = Teamlead;
}
void Score::Notify() {
	driverlead->UpdateDriverLeaderBoard(driverName,Score);
	Teamlead->UpdateLeaderBoard(TeamName,driverName, Score);
	
}

int Score::getscore()
{
	return this score;
}
	
void setscore(int s)
{
	this->score = s;
}
	
std::string getdriverName()
{
	return this->driverName;
}

std::string getTeamName()
{
	return this->TeamName;
}

void setdriverName(std::string Name)
{
	this->driverName = Name;
}

void setTeamName(std::string Name)
{
	this->TeamName = Name;
}
