//
// Created by jo-anne on 2020/10/22.
//

#ifndef LOGISTICS_ITERATOR_H
#define LOGISTICS_ITERATOR_H

namespace log {
    class Race;

    class Iterator {
    public:
        virtual void first() = 0;

        virtual void operator++() = 0; //virtual void next() = 0;
        virtual void operator--() = 0;//virtual void prev() = 0;
        virtual bool isLast() = 0;

        virtual Race *currentItem() = 0;
    };

}
//slicing?




#endif //LOGISTICS_ITERATOR_H
