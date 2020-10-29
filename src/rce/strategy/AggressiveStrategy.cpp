#include "AggressiveStrategy.h"

CreateStrategy* AggressiveStrategy::execute() 
{
	return this;
}

AggressiveStrategy::AggressiveStrategy(int p,int* t,int risk) 
{
	cout<<"The startegists have decided to implement an aggressive strategy"<<endl;
	Pitstops=p;
	tyres=t;
	riskLevel=risk;
}
