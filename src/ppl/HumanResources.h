#ifndef PEOPLE_HUMANRESOURCES_H
#define PEOPLE_HUMANRESOURCES_H

namespace ppl {
    class HumanResources {

    public:
        Person *hire(std::string job);

    protected:
        virtual Person *source() = 0;
    };
}

#endif
