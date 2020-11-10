#include <Doc.h>
#include "BlueprintStore.h"

using namespace eng;

Blueprint* BlueprintStore::getBlueprint() {
	Blueprint* temp = this->blueprint;
	this->blueprint = nullptr;
	return temp;
}

void BlueprintStore::setBlueprint(Blueprint* blueprint) {
	pr::Doc::detail("     \t{--Storing blueprint of component for later use--}\n");
    delete this->blueprint;
	this->blueprint = blueprint;
}

BlueprintStore::~BlueprintStore() {
    delete blueprint;
}
