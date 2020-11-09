#include "AggressiveStrategy.h"
using namespace rce;
CreateStrategy* AggressiveStrategy::execute() 
{
	return this;
}

AggressiveStrategy::AggressiveStrategy(int p,int* t,lg::RiskLevel risk)
{
    std::string print="The startegists have decided to implement an aggressive strategy\n";
    pr::Doc::midInfo(print);
	SetPitstops(p);
	SetTyres(t);
	SetRiskLevel(lg::Aggressive);
	SetStratName("Aggressive");
}

//AggressiveStrategy::~AggressiveStrategy()
//{
//
//}