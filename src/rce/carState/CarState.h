#ifndef CARSTATE_H
#define CARSTATE_H
#include <string>
namespace rce{
class CarState {
	private:
		CarState* carState;
	
public:
	virtual void handleChange() = 0;

	virtual std::string getCarState()=0;
    virtual ~CarState();
	CarState * getState();

	void setCarState(CarState * c);

};
}
#endif
