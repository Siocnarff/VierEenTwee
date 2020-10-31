#include "BlueprintStore.h"

using namespace eng;

Blueprint* BlueprintStore::getBlueprint() {
	Blueprint* temp = this->blueprint;
	this->blueprint = nullptr;
	return temp;
}

void BlueprintStore::setBlueprint(Blueprint* blueprint) {
	if (this->blueprint) {
		delete this->blueprint;
	}
	this->blueprint = blueprint;
}
