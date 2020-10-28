#ifndef RACING_DRIVERSLEADERBOARD_H
#define RACING_DRIVERSLEADERBOARD_H
#include <string>
#include "Leaderboard.h"
//namespace racing{
class DriversLeaderboard : public Leaderboard {

private:
	std::string driverName[20];
	int driverResult[20];
public:
	DriversLeaderboard();

	void display();

	int GetTeamScore(std::string TN);

	void createLeaderboard(std::string DriverName1,std::string DriverName2);

	void UpdateLeaderBoard(std::string TN,std::string DriverName, int Score) ;
	//void UpdateDriverLeaderBoard(std::string driverName, int Score);
	//used to update the indivitual scores of the driver then displays the output 
};
//}
#endif
