#include "ModerateStrategy.h"

using namespace rce;

CreateStrategy* ModerateStrategy::execute() 
{
	return this;
}

ModerateStrategy::ModerateStrategy(int p,int* t,lg::RiskLevel risk)
{
    std::string print="     --The strategists have decided to implement a moderate strategy\n";
    pr::Doc::midInfo(print);
    SetPitstops(p);
    SetTyres(t);
    SetRiskLevel(lg::Moderate);
    SetStratName("Moderate");
}

//ModerateStrategy::~ModerateStrategy()
//{
//
//}