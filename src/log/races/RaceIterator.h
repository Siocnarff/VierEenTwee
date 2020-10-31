//
// Created by jo-anne on 2020/10/22.
//

#ifndef LOGISTICS_RACEITERATOR_H
#define LOGISTICS_RACEITERATOR_H

#include "Iterator.h"
#include "Race.h"

namespace lg {
    class RacesList;

    class RaceIterator : public Iterator {
        friend class RacesList;

    public:
        RaceIterator();

        void first() override;

        virtual void operator++() override;  //void next() override;
        virtual void operator--() override;  //void prev() override;
        virtual bool operator==(const RaceIterator &) const;

        bool isLast() override;

        Race *currentItem() override;

    protected:
        RaceIterator(const RacesList &source, Race *pRace);

        Race *head;
        Race *current;
    };

}

#endif //LOGISTICS_RACEITERATOR_H
