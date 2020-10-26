#ifndef RACING_CARSTATE_H
#define RACING_CARSTATE_H
#include "../eng/Car.h"
namespace racing{
class CarState {

private:
	int damage;
	eng::Car * car;
public:
	CarState(eng::Car* c);
	
	virtual void handleChange(eng::Car* c, int d) = 0;

	virtual std::string getCarState();

	int getDamage();

	void setDamage(int damage);

	void Deal_damage(int d);
};
}
#endif
