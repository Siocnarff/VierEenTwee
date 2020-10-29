#include "SafeStrategy.h"

CreateStrategy* SafeStrategy::execute() 
{
	return this;
}

SafeStrategy::SafeStrategy(int p,int* t,int risk) 
{
	cout<<"The startegists have decided to implement a safe strategy"<<endl;
    SetPitstops(p);
    SetTyres(t);
    SetRiskLevel(risk);
    SetStratName("Safe");
}
