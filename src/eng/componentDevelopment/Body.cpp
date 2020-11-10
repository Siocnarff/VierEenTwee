#include "Body.h"

using namespace eng;

void Body::print() {
	pr::Doc::detail("\t\tBody Quality: " + std::to_string(getQualityLabel()) + "\n");
}

Component *Body::clone() {
    return new Body(this);
}

Body::Body(Component *toClone) : Component(toClone) {}

int Body::getId() {
    return 3;
}

Body::Body(int quality) : Component(quality) {

}
