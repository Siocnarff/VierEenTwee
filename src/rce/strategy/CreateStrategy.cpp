#include "CreateStrategy.h"

using namespace rce;

CreateStrategy* CreateStrategy::execute()
{
	// returns our final strategy// return this;
	return this;
}

CreateStrategy::CreateStrategy() 
{
	
}

lg::RiskLevel CreateStrategy::getRiskLevel()
{
	return riskLevel;
}

void CreateStrategy::SetRiskLevel(lg::RiskLevel rl)
{
    riskLevel=rl;
}

void CreateStrategy::SetPitstops(int p)
{
	Pitstops=p;
}

 void CreateStrategy::SetTyres(int *t)
 {
 	tyres=t;
 }

 void CreateStrategy::SetStratName(std::string s)
 {
     StratName=s;
 }

 int* CreateStrategy::getTyres()
 {
     return tyres;
 }
 int CreateStrategy::getPitstops()
 {
     return Pitstops;
 }

std::string CreateStrategy::getStratName()
 {
     return StratName;
 }

CreateStrategy::~CreateStrategy() = default;
