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
	// TODO - implement Component::createBlueprint
	throw "Not yet implemented";
}

void Component::rebuildComponent(Blueprint* plan) {
	// TODO - implement Component::rebuildComponent
	throw "Not yet implemented";
}

Component::Component(Component *component) {
    quality = component->quality;
    qualityLabel = component->qualityLabel;
}
