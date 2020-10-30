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

int CreateStrategy::getRiskLevel() 
{
	return risklevel;
}

void CreateStrategy::SetRiskLevel(int rl) 
{
	risklevel=rl;
}

void CreateStrategy::SetPitstops(int p)
{
	Pitstops=p;
}

 void CreateStrategy::SetTyres(int *t)
 {
 	tyres=t;
 }

 void CreateStrategy::SetStratName(string s)
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

 string CreateStrategy::getStratName()
 {
     return StratName;
 }