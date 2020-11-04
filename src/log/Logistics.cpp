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
#include <races/Box.h>
#include <races/GarageEquipment.h>
#include <races/CateringEquipment.h>
#include <factories/HireDriver.h>
#include "enums/randomisation.h"

using namespace lg;

/**
 * @author Jo
 * @status Done and dusted!
 */
Logistics::Logistics(int numDriverCarPairs) {
    numPairs = numDriverCarPairs;
    drivers.reserve(numDriverCarPairs);
    carsInSeasonIDs.reserve(numDriverCarPairs);
    seasonPointTally.reserve(numDriverCarPairs);
    transportManager = nullptr;
    raceIterator = nullptr;
    racingCalendar = nullptr;
    europeanContainer = nullptr;
    currentTeamStrategy = nullptr;
    budget = -1;
}

Logistics::~Logistics() {
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
        //colleague->notify(true);
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
    callEngDept()->resetTickets();

    //4. putRacesIntoCalender();
    putRacesIntoCalender();

    //5. Hire drivers
    ppl::HireDriver driverCurator;
    for (int i = 0; i < numPairs; ++i) {
        drivers.push_back(static_cast<ppl::Driver *>(driverCurator.hire("Driver")));
    }

    //6. Set drivers' home tracks
    for (ppl::Driver *d : drivers) {        //for each driver
        for (int i = 0; i < abs(rand() % 5) + 1; ++i) { //# home tracks in [1,5]
            d->addHomeTrack(abs(rand() % racingCalendar->getNumRaces())); //pick one of number of races
        }
    }

    //7. hire transportManager
    transportManager = new Road;
    transportManager->addAMethod(new Ship);
    transportManager->addAMethod(new Fly);

}

/**
 * @status Theoretically this one's done as well
 * @author Jo
 */
void Logistics::preSeasonPreparation() {
    // 1. Get strategy
    currentTeamStrategy = callRacingDept()->PlanSeasonStrategy(budget /*+ something else? */ );
    cout << "The Strategists of the " << callRacingDept()->getTeamName() << " team have decided on a strategy: "
         << currentTeamStrategy->getStratName() << std::endl;

    // 1.1 Notified about tyres (in the meanwhile)
    // 1.2 Receive Order
    std::cout << "Tyre Order has arrived" << endl;
    //tyreSpecs->printStats(); //not always

    //2. Pack containers
    cout << "Ordering the necessary tooleries and garage equipment thingamabobs\n";
    packContainers();

    //3. Train drivers
    driverBootCamp();

    //4.Inform engDept of riskLevel
    callEngDept()->setRiskLevel(currentTeamStrategy->getRiskLevel());

    //5. Build the cars
    for (int i = 0; i < numPairs; ++i) {
        carsInSeasonIDs.push_back(callEngDept()->buildCar(budget));
    }
}

/**
 * @status finito
 * @author Jo
 */
void Logistics::packContainers() {
    //european container
    europeanContainer = packSingleContainer();

    //non-european containers
    for (RaceIterator t = racingCalendar->begin(); !(t == racingCalendar->end()); ++t) {
        if (!t.currentItem()->isRaceEuropean()) {   //not european
            nonEuropeanContainers.push_back(packSingleContainer());
        } else if (t.currentItem()->isRaceEuropean()) {
            continue;
        }
    }
    cout << "Packed all containers" << endl;
}

/**
 * @author Marike
 * @status She be done
 * @return Packed Container
 */
Container *Logistics::packSingleContainer() {
    Box *box = new Box();
    auto *garageEquip = new GarageEquipment();
    auto *cateringEquip = new CateringEquipment();

    box->addElement(garageEquip);
    box->addElement(cateringEquip);

    cout << "Packed a container" << endl;

    return box;

}


// TODO : Check again
void Logistics::simulateEvent(Race *r) {
    //1. Transport every car from factory to race location and fill up our list to send to race
    vector<eng::Car *> carClipboard;
    for (int id : carsInSeasonIDs) {
        eng::Car *temp = callEngDept()->checkCarOutOfFactory(id);
        transportManager->transport(nullptr, r, temp);
        carClipboard.push_back(temp);
    }

    //2. get correct container and send to people pre-race arrival
    if (r->isRaceEuropean()) {
        // TODO : add fly functionality for drivers
        callRacingDept()->preRaceArrival(carClipboard, drivers, r, getEuropeanContainer(), tyreSpecs);
    } else {
        callRacingDept()->preRaceArrival(carClipboard, drivers, r, getNextNonEuropean(), tyreSpecs);
    }

    //4. racing weekend finishes and get points for each pair
    int *temp = callRacingDept()->RaceWeekend();
    for (int i = 0; i < numPairs; ++i) {
        seasonPointTally[i] += temp[i];
    }

    //5. finish the packup
    Container *tCont = callRacingDept()->postRacePackUp();
    if (!r->isRaceEuropean()) {
        delete tCont; //nonEuropeanContainer won't be used again
    } //else stay with the container

}

/**
 * @author Jo
 * @status nearly there
 * @ERROR hard-coded file path
 */
// TODO : Fix hard-coded file-path
void Logistics::putRacesIntoCalender() {
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

    racingCalendar->printList();

}

void Logistics::raceSeason() {
    //And the season starts
    pr::Doc::summary("And the season begins!");
    for (RaceIterator t = racingCalendar->begin(); !(t == racingCalendar->end()); ++t) {
        simulateEvent(t.currentItem());
    }
}


//NOT STARTED
// TODO : get leaderboard from racingDept and decide accordingly
void Logistics::postSeasonDebrief() {
    //1. Get results
    int *tumTumTum = callRacingDept()->getFinalResults();

    //2. Flashy results
    //Decorator here?

    //3. let transportManager take a holiday
    //Implement destructors

    //4. Let driver take a holiday

    //5. start building a new car?

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


//TODO : Decide on regime based on riskLevel
//IDEA: Change to command?
void Logistics::driverBootCamp() {
/*moet meer spesifiek wees hierso. gaan ons van hulle verwag of gaan ons self check dat die driver genoeg xp het?
    Dalk kan ons dit volgens riskLevel doen*/
    for (ppl::Driver *d: drivers) {
        //randomise weathering
        callRacingDept()->trainDriver(d, rand() % 10 + 1, randomWC(), randomTL());
    }
}



// =========================== MEDIATOR ===========================

//TODO : Strategy for using windTunnel;
void Logistics::sendCarToFactory(eng::Car *car, Race *r) {
    transportManager->transport(r, nullptr, car);
    callEngDept()->carArrivesAtFactory(car);
    callEngDept()->improveCar(car->getId(), true);
}

//NOT STARTED - should transport container here
void Logistics::containerHasBeenPacked(Container *) {
    cout << "fly container" << endl;
}

/**
 * @status Should be done
 * @param tyreOrder
 */
void Logistics::orderTyres(int *tyreOrder) {
    pr::Doc::summary("Ordering tyres as informed by Racing Departement\n");
    pr::Doc::detail("Tedious paperwork to complete tyre order\n");


    for (int i = 0; i < 3; ++i) {
        if (tyreOrder[0] != 0) {
            pr::Doc::detail("Ordering");
            pr::Doc::detail(to_string(tyreOrder[i]));
            pr::Doc::detail("pair(s) of ");
            switch (i) {
                case 0:
                    pr::Doc::detail("Soft Compound Tyres\n");
                    break;
                case 1:
                    pr::Doc::detail("Medium Compound Tyres\n");
                    break;
                case 2:
                    pr::Doc::detail("Hard Compound Tyres\n");
                    break;
            }
        }
    }


    //instantiate tyres
    tyreSpecs = new rce::Tyres(tyreOrder);
}



