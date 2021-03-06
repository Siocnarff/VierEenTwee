#ifndef ENG_BLUEPRINTSTORE_H
#define ENG_BLUEPRINTSTORE_H

#include "../componentDevelopment/Blueprint.h"

namespace eng {
	class BlueprintStore {

	private:
		Blueprint* blueprint = nullptr;

	public:
	    ~BlueprintStore();

		Blueprint* getBlueprint();

		void setBlueprint(Blueprint* blueprint);
	};
}

#endif
