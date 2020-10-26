#ifndef ENG_BLUEPRINTSTORE_H
#define ENG_BLUEPRINTSTORE_H

#include "../dev/Blueprint.h"

namespace eng {
	class BlueprintStore {

	private:
		dev::Blueprint* blueprint;

	public:
		dev::Blueprint* getBlueprint();

		void setBlueprint(dev::Blueprint* blueprint);
	};
}

#endif
