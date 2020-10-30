#include "ModerateStrategy.h"

using namespace rce;

CreateStrategy* ModerateStrategy::execute() 
{
	return this;
}

ModerateStrategy::ModerateStrategy(int p,int* t,int risk) 
{
	cout<<"The startegists have decided to implement a moderate strategy"<<endl;
    SetPitstops(p);
    SetTyres(t);
    SetRiskLevel(risk);
    SetStratName("Moderate");
}
