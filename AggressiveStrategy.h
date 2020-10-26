#ifndef AGGRESSIVESTRATEGY_H
#define AGGRESSIVESTRATEGY_H

#include "CreateStrategy.h"

class AggressiveStrategy :public CreateStrategy 
{
public:
	CreateStategy* execute();
	AggressiveStrategy();
};

#endif
