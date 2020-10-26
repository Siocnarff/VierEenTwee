#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include Score.h
#include <string>
class Leaderboard {

private:
	sting TeamName[3][15];
	int teamresult[3][15];
	string driverName[30];
	int driverResult[30];
	bool displayLeaderboards;


public:
	virtual void UpdateLeaderBoard(string TeamName,string DriverName, int Score) = 0;

	virtual void UpdateDriverLeaderBoard(String driverName, int Score) = 0;
	
	int GetTeamScore();
	void display();
	bool getdisplayLeaderboards();
	void setdisplayLeaderboards(bool b);
	//set if the leaderboard should be displayed
};

#endif
