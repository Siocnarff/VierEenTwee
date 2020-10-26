#ifndef CARSTATE_H
#define CARSTATE_H
#include "Car.h"
using namespace std;
class CarState {

private:
	int damage;
	Car * car;
public:
	CarState(Car* c);
	
	virtual void handleChange(Car* c, int d) = 0;

	virtual string getCarState();

	int getDamage();

	void setDamage(int damage);

	void Deal_damage(int d);
};

#endif
