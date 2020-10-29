#ifndef CREATESTRATEGY_H
#define CREATESTRATEGY_H

#include <iostream>
#include <string>
using namespace std;

class CreateStrategy 
{

private:
	int risklevel;
	int* tyres=new int[3];// 3 compounds in pairs and a wet compound [soft,meduim,hard]//only 5 pairs per weekend
	int Pitstops;//added
public:
	CreateStrategy* execute();
	CreateStrategy();
	int getRiskLevel();
	void SetRiskLevel(int rl);
	// void SetTyres();// only set in execute
	void SetPitstops(int p);
	// need some getters or make some of the members public
};

#endif
