#ifndef RACING_LEADERBOARD_H
#define RACING_LEADERBOARD_H
#include "Score.h"
#include <string>
namespace racing{
class Leaderboard {

private:
	std::sting TeamName[3][15];
	int teamresult[3][15];
	std::string driverName[30];
	int driverResult[30];
	bool displayLeaderboards;


public:
	Leaderboard();
	virtual void UpdateLeaderBoard(std::string TeamName,string DriverName, int Score) = 0;

	virtual void UpdateDriverLeaderBoard(std::string driverName, int Score) = 0;
	
	int GetTeamScore();
	void display();
	bool getdisplayLeaderboards();
	void setdisplayLeaderboards(bool b);
	//set if the leaderboard should be displayed
};
}
#endif
