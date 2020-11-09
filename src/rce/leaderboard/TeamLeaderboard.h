#ifndef TEAMLEADERBOARD_H
#define TEAMLEADERBOARD_H
#include "../pr/Doc.h"
#include <string>
#include "Leaderboard.h"
namespace rce{
class TeamLeaderboard : public rce::Leaderboard {
private:
		std::string TeamName[3][10];
		int teamresult[3][10];
		bool displayLeaderboard;
public:
	TeamLeaderboard();
	~TeamLeaderboard();

	void UpdateLeaderBoard(std::string TN,std::string DriverName, int Score);
	
	int GetTeamScore(std::string TN);
	
	void display();

	void createLeaderboard(std::string DriverName1,std::string DriverName2, int *score);
};
}
#endif
