#ifndef SAFESTRATEGY_H
#define SAFESTRATEGY_H

#include "CreateStrategy.h"

class SafeStrategy :public CreateStrategy 
{
public:
	CreateStrategy* execute();
	SafeStrategy(int p,int* t,int risk);
};

#endif
