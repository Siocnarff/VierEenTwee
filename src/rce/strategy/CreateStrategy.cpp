#include "CreateStrategy.h"

CreateStrategy* CreateStrategy::execute() 
{
	// returns our final strategy// return this;
	return NULL;
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

// void CreateStrategy::SetTires() 
// {
// 	// TODO - implement CreateStrategy::SetTires
// 	throw "Not yet implemented";
// }
