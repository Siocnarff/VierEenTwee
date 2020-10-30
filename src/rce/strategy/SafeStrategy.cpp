#include "SafeStrategy.h"
using namespace rce;
CreateStrategy* SafeStrategy::execute() 
{
	return this;
}

SafeStrategy::SafeStrategy(int p,int* t,log::RiskLevel risk)
{
	std::cout<<"The startegists have decided to implement a safe strategy"<<std::endl;
    SetPitstops(p);
    SetTyres(t);
    SetRiskLevel(risk);
    SetStratName("Safe");
}
