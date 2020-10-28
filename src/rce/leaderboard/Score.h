#ifndef RACING_SCORE_H
#define RACING_SCORE_H
#include <string>
#include "Leaderboard.h"
//namespace racing{
class Score {

private:
	int score;
	std::string driverName;
	std::string TeamName;
	Leaderboard* driverlead;
	Leaderboard* Teamlead;

public:
	Score(Leaderboard* driverlead,Leaderboard* Teamlead);
	
	void Notify();
		//notify when score is updated
	virtual void SetDriverScore(std::string driverName, int Score, std::string TeamName) = 0;
	
	int getscore();
	
	void setscore(int s);
	
	std::string getdriverName();

	std::string getTeamName();

	void setdriverName(std::string Name);

	void setTeamName(std::string Name);
	

};
#endif
