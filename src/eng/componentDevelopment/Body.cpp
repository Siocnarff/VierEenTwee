#include "Body.h"

using namespace eng;

void Body::print() {
	std::cout << "Body" << std::endl;
}

Component *Body::clone() {
    return new Body(this);
}

Body::Body(Component *toClone) : Component(toClone) {}
