#ifndef TEAMLEADERBOARD_H
#define TEAMLEADERBOARD_H
#include <string>
#include "Leaderboard.h"
//namespace racing{
class TeamLeaderboard : public Leaderboard {
private:
		std::string TeamName[3][10];
		int teamresult[3][10];
		bool displayLeaderboard;
public:
	TeamLeaderboard();

	void UpdateLeaderBoard(std::string TN,std::string DriverName, int Score);
	
	int GetTeamScore(std::string TN);
	
	void display();

	void createLeaderboard(std::string DriverName1,std::string DriverName2);

	//bool getdisplayLeaderboard();

	//void setdisplayLeaderboard(bool b);
	//update the team leaderboard and displaces the result
};
//}
#endif
