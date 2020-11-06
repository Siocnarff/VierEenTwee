#include "ModerateStrategy.h"

using namespace rce;

CreateStrategy* ModerateStrategy::execute() 
{
	return this;
}

ModerateStrategy::ModerateStrategy(int p,int* t,lg::RiskLevel risk)
{
//	std::cout<<"The startegists have decided to implement a moderate strategy"<<std::endl;
    SetPitstops(p);
    SetTyres(t);
    SetRiskLevel(lg::Moderate);
    SetStratName("Moderate");
}
