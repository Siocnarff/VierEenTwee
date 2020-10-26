#ifndef DEV_COMPONENT_H
#define DEV_COMPONENT_H

#include "Blueprint.h"

namespace dev {
	class Component {

	private:
		int quality;
		int damage;
		int qualityLabel;

	public:
		int getQualityLabel();

		void setQualityLabel(int qualityLabel);

		virtual void print() = 0;

		Blueprint* createBlueprint();

		void rebuildComponent(Blueprint* plan);
	};
}

#endif
