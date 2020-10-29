#include "ModerateStrategy.h"

CreateStrategy* ModerateStrategy::execute() 
{
	return this;
}

ModerateStrategy::ModerateStrategy(int p,int* t,int risk) 
{
	cout<<"The startegists have decided to implement a moderate strategy"<<endl;
	Pitstops=p;
	tyres=t;
	riskLevel=risk;
}
