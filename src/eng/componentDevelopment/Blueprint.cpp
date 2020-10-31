#include <vector>
#include "Blueprint.h"

using namespace eng;

std::vector<int> Blueprint::getState() {
	return state;
}

void Blueprint::setState(std::vector<int> state) {
	this->state = state;
}
