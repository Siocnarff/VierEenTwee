#ifndef PEOPLE_HUMANRESOURCES_H
#define PEOPLE_HUMANRESOURCES_H

namespace people {
	class HumanResources {


	public:
		people::Person* hire(std::string job);

	protected:
		virtual Person* source() = 0;
	};
}

#endif
