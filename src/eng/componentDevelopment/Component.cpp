#include "Component.h"
#include "Blueprint.h"

using namespace eng;

int Component::getQualityLabel() {
	return this->qualityLabel;
}

void Component::setQualityLabel(int qualityLabel) {
	this->qualityLabel = qualityLabel;
}

Blueprint* Component::createBlueprint() {
	Blueprint* blueprint = new Blueprint();
	std::vector<int> state{quality, damage, qualityLabel};
	blueprint->setState(state);
	return blueprint;
}

void Component::rebuildComponent(Blueprint* plan) {
	quality = plan->getState()[0];
	damage = plan->getState()[1];
	qualityLabel = plan->getState()[2];
}

Component::Component(Component *component) {
    quality = component->quality;
    qualityLabel = component->qualityLabel;
}
