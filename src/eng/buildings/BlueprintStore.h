#ifndef ENG_BLUEPRINTSTORE_H
#define ENG_BLUEPRINTSTORE_H

#include "../dev/Blueprint.h"

namespace eng {
	class BlueprintStore {

	private:
		Blueprint* blueprint;

	public:
		Blueprint* getBlueprint();

		void setBlueprint(Blueprint* blueprint);
	};
}

#endif
