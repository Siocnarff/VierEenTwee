#include "Safe.h"

using namespace eng;

int Safe::trySomethingNew() {
	std::default_random_engine generator(rand());
	std::normal_distribution<float> distribution(10,10);
	double num = distribution(generator);
	if (num < -50) {
		num = -50;
	} else if (num > 50){
		num = 50;
	}
	return (int)num;
}
