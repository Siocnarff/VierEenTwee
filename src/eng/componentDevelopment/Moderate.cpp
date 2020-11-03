#include <iostream>
#include "Moderate.h"

using namespace eng;

int Moderate::trySomethingNew() {
	std::default_random_engine generator(rand());
	std::normal_distribution<float> distribution(15,25);
	double num = distribution(generator);
	if (num < -50) {
		num = -50;
	} else if (num > 50){
		num = 50;
	}
	return (int)num;
}
