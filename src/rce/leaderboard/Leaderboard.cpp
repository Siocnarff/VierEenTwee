#include "Leaderboard.h"

using namespace rce;

Leaderboard::Leaderboard(){}

bool Leaderboard::getdisplayLeaderboard()
{
	return displayLeaderboards;
}
void Leaderboard::setdisplayLeaderboard(bool b)
{
	this->displayLeaderboards = b;
}
