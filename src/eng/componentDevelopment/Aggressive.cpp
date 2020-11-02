#include "Aggressive.h"

using namespace eng;

int Aggressive::trySomethingNew() {
	std::default_random_engine generator(rand());
	std::normal_distribution<float> distribution(15,35);
	double num = distribution(generator);
	if (num < -50) {
		num = -50;
	} else if (num > 50){
		num = 50;
	}
	return (int)num;
}
