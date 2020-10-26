#include "BlueprintStore.h"
#include "../dev/Blueprint.h"

dev::Blueprint* eng::BlueprintStore::getBlueprint() {
	return this->blueprint;
}

void eng::BlueprintStore::setBlueprint(dev::Blueprint* blueprint) {
	this->blueprint = blueprint;
}
