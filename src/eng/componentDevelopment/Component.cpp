#include "Component.h"
#include "Blueprint.h"

using namespace eng;

int Component::getQualityLabel() const {
	return this->qualityLabel;
}

void Component::setQualityLabel(int label) {
	this->qualityLabel = label;
}

Blueprint* Component::createBlueprint() {
	auto* blueprint = new Blueprint();
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
    qualityLabel = component->qualityLabel;
    quality = component->quality;
    damage = component->damage;
}

Component::Component(int quality) {
    this->quality = quality;
}