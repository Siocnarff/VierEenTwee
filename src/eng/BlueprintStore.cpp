#include "BlueprintStore.h"
#include "../dev/Blueprint.h"

using namespace eng;

Blueprint* BlueprintStore::getBlueprint() {
	return this->blueprint;
}

void BlueprintStore::setBlueprint(Blueprint* blueprint) {
	this->blueprint = blueprint;
}
