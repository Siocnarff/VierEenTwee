#include <iostream>

#include "enums.h"
#include "Container.h"
#include "SubStates.h"
#include "RaceIterator"
#include "RacesList.h"

void testIterator(){
    string names[5] = {"malibu", "florence", "florida", "vermont","venice"};
    TrackComplexity complexity[5] = {Difficult, Easy, Extreme, Average, Easy};
    bool european[5] = {1,0,1,1,0};
    RacesList* raceList = new RacesList;
    for (int i = 0; i < 5; ++i) {
        raceList->addRace(new Race(names[i], complexity[i], european[i]));
    }

    Race* temp = raceList->getHeadRace();
    while (temp!= NULL) {
        cout << temp->getLocation() << endl;
        temp = temp->nextRace();
    }
    cout << endl;

    for (RaceIterator t = raceList->begin(); !(t==raceList->end()) ; ++t) {
        cout << t.currentItem()->getLocation() << endl;
    }
    cout << endl;

    raceList->addRace(new Race("vantance", Easy, 0));
    for (RaceIterator t = raceList->begin(); !(t==raceList->end()) ; ++t) {
        cout << t.currentItem()->getLocation() << endl;
    }

}

void testContainerState() {
    Container* container = new Container();
    cout << endl;

    for (int i = 0; i < 4; ++i) {
        cout << container->getState() << endl;
        container->advanceState();
    }

    cout << "\nWacky Containers!" << endl;
}

int main() {

  
   testIterator();

    testContainerState();

    return 0;
}
