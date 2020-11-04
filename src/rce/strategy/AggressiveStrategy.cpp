#include "AggressiveStrategy.h"
using namespace rce;
CreateStrategy* AggressiveStrategy::execute() 
{
	return this;
}

AggressiveStrategy::AggressiveStrategy(int p,int* t,int risk) 
{
	std::cout<<"The startegists have decided to implement an aggressive strategy"<<std::endl;
	SetPitstops(p);
	SetTyres(t);
	SetRiskLevel(lg::Aggressive);
	SetStratName("Aggressive");
}
