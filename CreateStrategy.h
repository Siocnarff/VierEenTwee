#ifndef CREATESTRATEGY_H
#define CREATESTRATEGY_H

#include <iostream>

class CreateStrategy 
{

private:
	int risklevel;
	int tyres*=new int[3];// 3 compounds in pairs 
	int NrOfPitstops;//added
public:
	CreateStategy* execute();
	CreateStrategy(int b);
	int getRiskLevel();
	void SetRiskLevel(int rl);
	// void SetTyres();// only set in execute
	void SetPitstops();
	// need some getters or make some of the members public
};

#endif
