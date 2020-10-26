#include "Component.h"
#include "Blueprint.h"

int dev::Component::getQualityLabel() {
	return this->qualityLabel;
}

void dev::Component::setQualityLabel(int qualityLabel) {
	this->qualityLabel = qualityLabel;
}

dev::Blueprint* dev::Component::createBlueprint() {
	// TODO - implement Component::createBlueprint
	throw "Not yet implemented";
}

void dev::Component::rebuildComponent(dev::Blueprint* plan) {
	// TODO - implement Component::rebuildComponent
	throw "Not yet implemented";
}
