#ifndef MODERATESTRATEGY_H
#define MODERATESTRATEGY_H

#include "CreateStrategy.h"

class ModerateStrategy :public CreateStrategy 
{
public:
	CreateStrategy* execute();
	ModerateStrategy();
};

#endif
