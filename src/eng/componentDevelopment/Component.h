#ifndef DEV_COMPONENT_H
#define DEV_COMPONENT_H

#include "Blueprint.h"

namespace eng {
	class Component {
	friend class Car;
	private:
		int quality = 0;
		int damage = 0;
		int qualityLabel = 0;

	public:
		int getQualityLabel();

		void setQualityLabel(int qualityLabel);

		virtual void print() = 0;

		Blueprint* createBlueprint();

		void rebuildComponent(Blueprint* plan);
	};
}

#endif
