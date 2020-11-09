#include "ModerateStrategy.h"

using namespace rce;

CreateStrategy* ModerateStrategy::execute() 
{
	return this;
}

ModerateStrategy::ModerateStrategy(int p,int* t,lg::RiskLevel risk)
{
//	std::cout<<"The startegists have decided to implement a moderate strategy"<<std::endl;
    std::string print="The startegists have decided to implement a moderate strategy\n";
    pr::Doc::midInfo(print);
    SetPitstops(p);
    SetTyres(t);
    SetRiskLevel(lg::Moderate);
    SetStratName("Moderate");
}
