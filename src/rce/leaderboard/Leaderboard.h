#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include "../pr/Doc.h"
#include <string>
namespace rce{
class Leaderboard {

private:
	bool displayLeaderboards;	
	int finalScore[20];
	std::string DriverName[20];
	int RaceCounter;
	std::string OurDriver[2];
    int * finalresult;
public:
	Leaderboard();
	virtual ~Leaderboard();
	virtual void UpdateLeaderBoard(std::string TN,std::string DriverName, int Score) = 0;
	//virtual void UpdateDriverLeaderBoard(std::string driverName, int Score) = 0;
	virtual void createLeaderboard(std::string DriverName1,std::string DriverName2 ,int *score)=0;
	virtual int GetTeamScore(std::string TN)=0;
	virtual void display()= 0;
	bool getdisplayLeaderboard() ;
	void setdisplayLeaderboard(bool b);
	void setDriver(std::string Driver1, std::string Driver2);
	void setFinalScore( int * score);
	int * getFinalScore();


	//set if the leaderboard should be displayed
};
}
#endif
