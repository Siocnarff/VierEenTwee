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
#include "ppl/factories/HireDriver.h"

using namespace lg;

/**
 * @author Jo
 * @status Done and dusted!
 */
Logistics::Logistics() {
    transportManager = nullptr;
    raceIterator = nullptr;
    racingCalendar = nullptr;
    europeanContainer = nullptr;
    currentTeamStrategy = nullptr;
    seasonPointTally[0] = -1;
    seasonPointTally[1] = -1;
    budget = -1;
}

/**
 * @status completed
 * @param colleague
 */
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
 * @status really finished
 */
void Logistics::doYearPlanning() {
    //1. getBudget from "Sponsors"
    budget = abs(rand() % 100 + 1);

    //2. Hire emplpoyees: each department
    for (auto const&[key, val] : departments) {
        val->hireEmployees(budget);
    }

    //3. Set tickets of racingDept;

    //4. putRacesIntoCalender();
    putRacesIntoCalender();

    //5. Hire drivers
    ppl::HireDriver driverCurator;
    drivers.push_back(static_cast<ppl::Driver*>(driverCurator.hire("Driver")));
    drivers.push_back(static_cast<ppl::Driver*>(driverCurator.hire("Driver")));

    //6. Set drivers' home tracks
    for (ppl::Driver* d : drivers) {        //for each driver
        for (int i = 0; i < abs(rand() % 5) + 1; ++i) { //possible home tracks - interval [1,5]
            d->addHomeTrack(abs(rand() % racingCalendar->getNumRaces())); //pick one of number of races
        }
    }

    //7. hire transportManager
    transportManager = new Road;
    transportManager->addAMethod(new Ship);
    transportManager->addAMethod(new Fly);

}

//IN THE WORKS
// TODO: decide on driver training regime
void Logistics::preSeasonPreparation() {
    // 1. Get strategy
    currentTeamStrategy = callRacingDept()->PlanSeasonStrategy(budget /*+ something else? */ );
    cout << "The Strategists of the " << callRacingDept()->getTeamName() << " team have decided on a strategy: " << currentTeamStrategy->getStratName() << std::endl;
    // 1.1 Notified about tyres (in the meanwhile)
    // 1.2 Receive Order
    std::cout << "Tyre Order has arrived" << endl;
    //tyreSpecs->printStats(); //not always

    //2. Pack containers
    cout << "Ordering the necessary tooleries and garage equipment thingamabobs\n";
    packContainers();

    //3. Train drivers
    driverBootCamp();

    //4.build the cars
//    carsInSeasonIDs.push_back(callEngDept()->buildCar(budget,currentTeamStrategy->getRiskLevel())); //tyres

    /*carsInSeason.push(buildCar()); //ons gaan bou die kar
    testCar();
    getRaceIterator();
   */

}


void Logistics::raceSeason() {
    for (RaceIterator t = racingCalendar->begin(); !(t==racingCalendar->end()) ; ++t) {
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

/*void Logistics::requestContainerStateChange(bool isEuropeanRace) {

}*/

Container *Logistics::getEuropeanContainer() {
    return europeanContainer;
}

Container *Logistics::getNextNonEuropean() {
    Container *back = nonEuropeanContainers.back();
    nonEuropeanContainers.pop_back();
    return back;
}

void Logistics::packContainers(int tyreCompound) {

    //Need to create container objects to match to races
    //Test by packing a single container:

    Container *container = packSingleContainer(tyreCompound);

    cout << "Packed all containers" << endl;

}

Container *Logistics::packSingleContainer(int tyreCompound) {
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

void Logistics::simulateEvent(Race *r) {
    //get car
    eng::Car* carInTransport = callEngDept()->checkCarOutOfFactory(carsInSeasonIDs[0]);
    //transport car
    transportManager->transport(nullptr, r, carInTransport);

    //get correct container and pre-race arrival
/*
    if (r->isRaceEuropean()) {
        callRacingDept()->preRaceArrival(carInTransport, driver, r, getEuropeanContainer());
    }
    else {
        callRacingDept()->preRaceArrival(carInTransport, driver, r, getNextNonEuropean());
    }
*/
    //racing weekend finishes and get points
/*
    int* temp = callRacingDept()->RacingWeekend();
    seasonPointTally[0]+= temp[0];
    seasonPointTally[1]+= temp[1];
*/
    //finish the packup
//    Container* tCont = callRacingDept()->postRacePackUp(); //execute
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
        infile.open("/home/jo-anne/Documents/VierEenTwee/src/lg/races/raceData.txt");
        //infile.open("src/lg/races/raceData.txt");
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

//JUST FINISH THE FINAL CELEBRATION
void Logistics::raceSeason() {
    for (RaceIterator t = racingCalendar->begin(); !(t == racingCalendar->end()); ++t) {
        simulateEvent(t.currentItem());
    }
    std::cout << std::endl;

    callRacingDept()->getResults();

    //2 cars
    //callRacingDept()->preRaceArrival(new eng::Car(3), driver, new Race, new Container);
//    callRacingDept()->preRaceArrival(new eng::Car(2), driver, new Race, new Box);

    //
    throw "Implement for two cars";
    //seasonPointTally += callRacingDept()->RacingWeekend();
    callRacingDept()->postRacePackUp(); //execute

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
        callRacingDept()->preRaceArrival(reinterpret_cast<eng::Car **>(carInTransport),
                                         reinterpret_cast<ppl::Driver **>(driver), r, getEuropeanContainer());
    } else {
        callRacingDept()->preRaceArrival(reinterpret_cast<eng::Car **>(carInTransport),
                                         reinterpret_cast<ppl::Driver **>(driver), r, getNextNonEuropean());
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

//NOT STARTED
void Logistics::postSeasonDebrief() {
    //start building a new car
    //let driver take holiday
    //let transportHandler take holiday

}



//===================== HELPER FUNCTIONS==================================

/**
 * @status done
 */
Container *Logistics::getEuropeanContainer() {
    return europeanContainer;
}

/**
 * @status fini
 * @return
 */
Container *Logistics::getNextNonEuropean() {
    Container *back = nonEuropeanContainers.back();
    nonEuropeanContainers.pop_back();
    return back;
}

/**
 * @author Jo
 * @status : Check and test (should be done)
 */
void Logistics::packContainers() {

    //1. Sonder tyres wat moet in
    for (RaceIterator t = racingCalendar->begin(); !(t == racingCalendar->end()); ++t) {
        //std::cout << t.currentItem()->getLocation() << std::endl;
        if (!t.currentItem()->isRaceEuropean()) {
            nonEuropeanContainers.push_back(packSingleContainer());
        } else if (t.currentItem()->isRaceEuropean() && getEuropeanContainer() == nullptr) {
            europeanContainer = packSingleContainer();
        } else {
            //do nothing
        }
    }
    cout << "Packed all containers" << endl;

}

Container *Logistics::packSingleContainer() {
    Box *box = new Box();
    GarageEquipment *garageEquip = new GarageEquipment();
    CateringEquipment *cateringEquip = new CateringEquipment();

    box->addElement(garageEquip);
    box->addElement(cateringEquip);

    cout << "Packed a container" << endl;

    return box;

}


/**
 * @author Jo
 * @return RacingDept Instance
 * @status definitely done
 */
rce::RacingDep *Logistics::callRacingDept() {
    return dynamic_cast<rce::RacingDep *>(departments['r']);
}

/**
 * @author Jo
 * @return EngTeam Instance
 * @status absolutely done
 */
eng::EngTeam *Logistics::callEngDept() {
    return dynamic_cast<eng::EngTeam *>(departments['e']);
}

/**
 * @author Jo
 * @details console output or not
 * @status if it works it should be done
 */
void Logistics::toggleVerbose() {
    verbose = !verbose;
}

//TODO : Decide on regime based on
//IDEA: Change to command?
void Logistics::driverBootCamp() {
/*moet meer spesifiek wees hierso. gaan ons van hulle verwag of gaan ons self check dat die driver genoeg xp het?
    Dalk kan ons dit volgens riskLevel doen*/
    for (ppl::Driver* d: drivers) {
        //randomise weathering
        callRacingDept()->trainDriver(d, rand()%10+1, randomTL(), randomWC());
    }
}



// =========================== MEDIATOR ===========================

//DONE
void Logistics::sendCarToFactory(eng::Car *car) {
    cout << "send car to factory" << endl;
    transportManager->transport(new Race, new Race, car);
    callEngDept()->carArrivesAtFactory(car);
    callEngDept()->improveCar(car->getId());
}

//NOT STARTED - should transport container here
void Logistics::containerHasBeenPacked(Container *) {
    cout << "fly container" << endl;
}

//IN THE WORKS - DECIDE WHETHER TO INSTANTIATE OR NOT
void Logistics::orderTyres(int *tyreOrder) {
    std::cout << "Tedious paperwork to complete tyre order" << std::endl;
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


    //instantiate tyres
    tyreSpecs = new rce::Tyres(tyreOrder);
}

Logistics::~Logistics() {
}


