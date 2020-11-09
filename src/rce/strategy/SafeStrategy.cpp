#include "SafeStrategy.h"

using namespace rce;

CreateStrategy* SafeStrategy::execute() 
{
	return this;
}

SafeStrategy::SafeStrategy(int p,int* t,lg::RiskLevel risk)
{
    std::string print="The startegists have decided to implement a safe strategy\n";
    pr::Doc::midInfo(print);
    SetPitstops(p);
    SetTyres(t);
    SetRiskLevel(lg::Safe);
    SetStratName("Safe");
}

//SafeStrategy::~SafeStrategy()
//{
//
//}