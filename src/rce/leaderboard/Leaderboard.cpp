#include "Leaderboard.h"

Leaderboard::Leaderboard(){}

bool Leaderboard::getdisplayLeaderboard()
{
	return displayLeaderboards;
}
void Leaderboard::setdisplayLeaderboard(bool b)
{
	this->displayLeaderboards = b;
}
