#ifndef SAFESTRATEGY_H
#define SAFESTRATEGY_H

#include "CreateStrategy.h"

class SafeStrategy :public CreateStrategy 
{
public:
	CreateStategy* execute();
	SafeStrategy();
};

#endif
