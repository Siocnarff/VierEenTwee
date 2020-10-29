#ifndef AGGRESSIVESTRATEGY_H
#define AGGRESSIVESTRATEGY_H

#include "CreateStrategy.h"

class AggressiveStrategy :public CreateStrategy 
{
public:
	AggressiveStrategy();
	CreateStrategy* execute(int p,int* t,int risk);
	
};

#endif
