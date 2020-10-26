#ifndef SCORE_H
#define SCORE_H
#include <string>
class Score {

private:
	int Score;
	string driverName;
	string TeamName;

public:
	void Notify();
		//notify when score is updated
	virtual void SetDriverScore(string driverName, int Score, string TeamName, bool display) = 0;
};

#endif
