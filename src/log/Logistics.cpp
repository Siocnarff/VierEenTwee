//
// Created by jo on 2020/10/09.
//

#include "transportation/Fly.h"
#include "transportation/Ship.h"
#include "transportation/Road.h"
#include "Logistics.h"
#include "RacesList.h"

#include <fstream>
#include <sstream>
#include <log/races/Box.h>
#include <log/races/GarageEquipment.h>
#include <log/races/CateringEquipment.h>
#include <log/races/TyreBox.h>


using namespace log;

/**
 * @author Jo
 */
Logistics::Logistics() {
    driver = nullptr;
    transportManager = nullptr;
    raceIterator = nullptr;
    racingCalendar = nullptr;
    europeanContainer = nullptr;
    currentTeamStrategy = nullptr;
    seasonPointTally[0] = -1;
    seasonPointTally[1] = -1;
    budget = -1;
}

void Logistics::registerNotifier(Colleague *colleague) {
    auto *temp = new eng::EngTeam;
    if (typeid(*temp) == typeid(*colleague)) {
        departments.insert(pair<char, Colleague *>('e', colleague));
    } else {
        colleague->notify(true);
        departments.insert(pair<char, Colleague *>('r', colleague));
    }
    colleague->addObserver(this);

}


/**
 * @author Jo
 * @status done!
 */
void Logistics::doYearPlanning() {
    //1. getBudget from "Sponsors"
    budget = abs(rand() % 100 + 1);
    //2. Hire emplpoyees: each department
    for (auto const&[key, val] : departments) {
        val->hireEmployees(budget);
    }
    //3. putRacesIntoCalender();
    putRacesIntoCalender();
    //4. hire driver
    driver = new ppl::Driver("Fluffy McAllen", 0, 0);
    //5. Set home tracks
    for (int i = 0; i < abs(rand() % 5) + 1; ++i) { //interval [1,5]
        driver->addHomeTrack(abs(rand() % racingCalendar->getNumRaces())); //pick one of number of races
    }
    //6. hire transportManager
    transportManager = new Road;
    transportManager->addAMethod(new Ship);
    transportManager->addAMethod(new Fly);

}


void Logistics::preSeasonPreparation() {
    // 1. Get strategy
    currentTeamStrategy = callRacingDept()->PlanSeasonStrategy(budget /*+ something else? */ );
    // 1.1 Notified about tyres

    // 1.2 Instantiate tyres
    // x x x
    std::cout << "Tyre Order has arrived" << endl;


    //Pack containers right after tyre compound received

    int tyrecompound = 2;

    packContainers(tyrecompound);

    //moet meer spesifiek wees hierso.
    //gaan ons van hulle verwag of gaan ons self check dat die driver genoeg xp het?
    //Dalk kan ons dit volgens riskLevel doen
    callRacingDept()->trainDriver(new ppl::Driver("s", 0, 0), 15, Rainy, Average);

    //order stuff

    //build cars x2
//    carsInSeasonIDs.push_back(callEngDept()->buildCar(budget,currentTeamStrategy->getRiskLevel())); //tyres

    /*carsInSeason.push(buildCar()); //ons gaan bou die kar
    testCar();
    getRaceIterator();
   */

}


void Logistics::raceSeason() {
    for (RaceIterator t = racingCalendar->begin(); !(t == racingCalendar->end()); ++t) {
        //std::cout << t.currentItem()->getLocation() << std::endl;
        simulateEvent(t.currentItem());
    }
    std::cout << std::endl;

    //2 cars
    //callRacingDept()->preRaceArrival(new eng::Car(3), driver, new Race, new Container);
//    callRacingDept()->preRaceArrival(new eng::Car(2), driver, new Race, new Box);

    //
    throw "Implement for two cars";
    //seasonPointTally += callRacingDept()->RacingWeekend();
    callRacingDept()->postRacePackUp(); //execute

}

void Logistics::postSeasonDebrief() {
//maybe do some analysis?
    //start building a new car
    //let driver take holiday
    //let transportHandler take holiday

}

void Logistics::sendCarToFactory(eng::Car *car) {
    cout << "send car to factory" << endl;
    transportManager->transport(new Race, new Race, car);
    callEngDept()->carArrivesAtFactory(car);
    callEngDept()->improveCar(car->getId());
}

void Logistics::containerHasBeenPacked(Container *) {
    cout << "fly container" << endl;
}

Container *Logistics::getEuropeanContainer() {
    return europeanContainer;
}

Container *Logistics::getNextNonEuropean() {
    Container *back = nonEuropeanContainers.back();
    nonEuropeanContainers.pop_back();
    return back;
}

void Logistics::packContainers(int *tyreCompoundOrder) {

    //As ons werk sonder tyres wat moet in
    for (RaceIterator t = racingCalendar->begin(); !(t == racingCalendar->end()); ++t) {
        //std::cout << t.currentItem()->getLocation() << std::endl;
        if (!t.currentItem()->isRaceEuropean()) {
            nonEuropeanContainers.push_back(packSingleContainer(false));
        } else if (t.currentItem()->isRaceEuropean() && getEuropeanContainer() == nullptr) {
            europeanContainer = packSingleContainer(true);
        } else
            (//do nothing
            )
    }

    //As ons werk met tyres wat moet in
    for (RaceIterator t = racingCalendar->begin(); !(t == racingCalendar->end()); ++t) {
        //std::cout << t.currentItem()->getLocation() << std::endl;
        if (!t.currentItem()->isRaceEuropean()) {
            nonEuropeanContainers.push_back(packSingleContainer(tyreCompoundOrder));
        } else if (t.currentItem()->isRaceEuropean() && getEuropeanContainer() == nullptr) {
            europeanContainer = packSingleContainer(tyreCompoundOrder);
        } else
            (//do nothing
            )
    }

    //As ons besluit om te pak voor 'n resies elke keer dan is hierdie hele deel van die kode onnuttig.




    /*Need to create container objects to match to races
    Test by packing a single container:
    Container *container = packSingleContainer(tyreCompound);*/

    cout << "Packed all containers" << endl;

}

Container *Logistics::packSingleContainer(int *tyreCompound) {
    Box *box = new Box();
    auto *garageEquip = new GarageEquipment();
    auto *cateringEquip = new CateringEquipment();
    auto *tyreBox = new TyreBox(tyreCompound);

    box->addElement(garageEquip);
    box->addElement(cateringEquip);
    box->addElement(tyreBox);

    cout << "Packed a container" << endl;

    return box;

}

/**
 * @author Jo
 * @param race
 */
void Logistics::simulateEvent(Race *r) {
    //1. get car
    eng::Car *carInTransport = callEngDept()->checkCarOutOfFactory(carsInSeasonIDs[0]);
    //2. transport car
    transportManager->transport(nullptr, r, carInTransport);

    //3. get correct container and pre-race arrival
    if (r->isRaceEuropean()) {
        callRacingDept()->preRaceArrival(carInTransport, driver, r, getEuropeanContainer());
    } else {
        callRacingDept()->preRaceArrival(carInTransport, driver, r, getNextNonEuropean());
    }
    //4. racing weekend finishes and get points
    int *temp = callRacingDept()->RacingWeekend();
    seasonPointTally[0] += temp[0];
    seasonPointTally[1] += temp[1];
    //5. finish the packup
    Container *tCont = callRacingDept()->postRacePackUp(); //execute
    if (!r->isRaceEuropean()) {
        delete tCont; //nonEuropeanContainer won't be used again
    } //else stay with the container

}

/**
 * @author Jo
 * @status nearly there
 * @ERROR hard-coded file path
 */
void Logistics::putRacesIntoCalender() {
    // TODO : File path hard-coded. Needs to change
    racingCalendar = new RacesList;

    try {
        std::ifstream infile;
        infile.open("/home/jo-anne/Documents/VierEenTwee/src/log/races/raceData.txt");
        //infile.open("src/log/races/raceData.txt");
        int numRaces;
        infile >> numRaces;

        std::string name;
        int complexity;
        bool inEurope;
        int laps;
        getline(infile, name); //to remove first random /n
        for (int i = 0; i < numRaces; ++i) {
            std::getline(infile, name);
            infile >> complexity;
            infile >> inEurope;
            infile >> laps;
            Race *newRace = new Race(name, complexity, inEurope, laps);
            racingCalendar->addRace(newRace);
            getline(infile, name); //to remove first random /n
        }
        infile.close();
    } catch (std::ifstream::failure e) { //exception e
        std::cout << "There was a file-reading error !\n";
    }

    if (verbose) {
        racingCalendar->printList();
    }

}

/**
 * @author Jo
 * @return RacingDept Instance
 * @status Done
 */
rce::RacingDep *Logistics::callRacingDept() {
    return dynamic_cast<rce::RacingDep *>(departments['r']);
}

/**
 * @author Jo
 * @return EngTeam Instance
 * @status Done
 */
eng::EngTeam *Logistics::callEngDept() {
    return dynamic_cast<eng::EngTeam *>(departments['e']);
}


/**
 * @author Jo
 * @details console output or not
 * @status In Progress
 */
void Logistics::toggleVerbose() {
    verbose = !verbose;
}

void Logistics::orderTyres(int *tyreOrder) {
    if (!verbose) {
        std::cout << "Tedious paperwork to complete tyre order" << std::endl;
    }
    if (tyreOrder[0] != 0) {
        if (verbose) {
            std::cout << "Ordering " << tyreOrder[0] << "pair(s) of Soft Compound Tyres" << std::endl;
        }
    }

    if (tyreOrder[1] != 0) {
        if (verbose) {
            std::cout << "Ordering " << tyreOrder[1] << "pair(s) of Medium Compound Tyres" <<
                      std::endl;
        }
    }
    if (tyreOrder[2] != 0) {
        if (verbose) {
            std::cout << "Ordering " << tyreOrder[2] << "pair(s) of Hard Compound Tyres" <<
                      std::endl;
        }
    }


//instantiate tyres or leave for later



}

