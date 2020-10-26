#ifndef RACING_SCORE_H
#define RACING_SCORE_H
#include <string>
namespace racing{
class Score {

private:
	int Score;
	std::string driverName;
	std::string TeamName;

public:
	void Notify();
		//notify when score is updated
	virtual void SetDriverScore(std::string driverName, int Score, std::string TeamName, bool display) = 0;
};
}
#endif
