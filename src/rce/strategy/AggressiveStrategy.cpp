#include "AggressiveStrategy.h"
using namespace rce;
CreateStrategy* AggressiveStrategy::execute() 
{
	return this;
}

AggressiveStrategy::AggressiveStrategy(int p,int* t,int risk) 
{
	cout<<"The startegists have decided to implement an aggressive strategy"<<endl;
	SetPitstops(p);
	SetTyres(t);
	SetRiskLevel(risk);
	SetStratName("Aggressive");
}
