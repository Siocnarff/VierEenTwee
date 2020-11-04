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
    sponsoredBudget();

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
        int rand_hom_tracks = abs(rand() % 5) + 1; //# home tracks in [1,5]
        for (int i = 0; i < rand_hom_tracks; ++i) {
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
    currentTeamStrategy = callRacingDept()->PlanSeasonStrategy(budget);
    //TODO : change to doc
    cout << "The Strategists of the " << callRacingDept()->getTeamName() << " team have decided on a strategy: "
         << currentTeamStrategy->getStratName() << std::endl;

    // 1.1 Notified about tyres (in the meanwhile)
    // 1.2 Receive Order
    std::cout << "Tyre Order has arrived" << endl;
    //tyreSpecs->printStats(); //moet ons dit so maak dat dit print op verskillende levels?

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



    pr::Doc::summary("Packed a container\n");
    box->print();
    pr::Doc::detail("\n");

    return box;

}


// TODO : Check again
void Logistics::simulateEvent(Race *r) {
    //1. Transport car (from factory to race location)
    //1.1 Fill up clipboard
    vector<eng::Car *> carClipboard;
    for (int id : carsInSeasonIDs) {
        eng::Car *temp = callEngDept()->checkCarOutOfFactory(id);
        transportManager->transport(nullptr, r, temp);
        carClipboard.push_back(temp);
    }

    //2. Transport Drivers
    pr::Doc::detail("The two drivers are transported in a luxury mode of transport to ");
    pr::Doc::detail(r->getLocation());

    //Transport drivers
    // TODO : add fly functionality for drivers

    //3. get correct container, transport and fly and fly

    transportManager->transport(r->prevRace(), r);
    if (r->isRaceEuropean()) {
        callRacingDept()->preRaceArrival(carClipboard, drivers, r, getEuropeanContainer(), tyreSpecs);
    } else {
        callRacingDept()->preRaceArrival(carClipboard, drivers, r, getNextNonEuropean(), tyreSpecs);
    }

    //4. racing weekend finishes and get points for each pair
    int *temp = callRacingDept()->RacingWeekend();
    for (int i = 0; i < numPairs; ++i) {
        seasonPointTally[i] += temp[i];
    }

    //5. finish the packup
    Container *tCont = callRacingDept()->postRacePackUp();
    if (!r->isRaceEuropean()) {
        delete tCont; //nonEuropeanContainer won't be used again
    } //else stay with the container
    //6. Transport drivers on and container back

}

/**
 * @author Jo
 * @status nearly there
 */
void Logistics::putRacesIntoCalender() {
    racingCalendar = new RacesList;

    std::ifstream infile;
    infile.open("../src/log/races/raceData.txt");

    if (infile.is_open()) {
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
    } else { //exception e
        std::cout << "There was a file-reading error !\n";
        throw "Error";
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
    delete transportManager;

    //4. Let driver take a holiday
    int sumPositions = 0;
    for (int i = 0; i < numPairs; ++i) {
        ppl::Driver *d = drivers.back();
        drivers.pop_back();
        if (tumTumTum[2*i+1] >= 3) {
            pr::Doc::detail(d->getName() + " takes a well-earned holiday near Malibu\n");
        } else {
            pr::Doc::detail(d->getName() + " is tactfully offered a retirement package\n");
        }
        sumPositions += tumTumTum[2*i+1];

    }

    //5. Get some sponsors again.
    sponsoredBudget(sumPositions);

    //5. start building a new car?
    pr::Doc::summary("Start working on a new car");
    for (int i = 0; i < numPairs; ++i) {
        carsInSeasonIDs.push_back(callEngDept()->buildCar(budget));
    }


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

void Logistics::sponsoredBudget(int sumPositions) {

    pr::Doc::summary("Approaching sponsors to negotiate a new budget");

    if (budget == 0) {  //default argument
        budget = abs(rand() % 100 + 1);
    }
    else {
        if (sumPositions >= 3) {
            pr::Doc::detail("Rolex is the team's next sponsor! Budget increases wildly");
            budget = max((int) ((double) budget * 1.5),(100- (int) ((double) budget * 0.5)))  ;
        } else if (sumPositions <= 6) {
            pr::Doc::detail("Emirates is the team's next sponsor! Budget increases wildly");
            budget = max((int) ((double) budget * 0.2),(80- (int) ((double) budget * 0.2)));
        } else if (sumPositions <= 10) {
            pr::Doc::detail("The sponsor is satisfied with the performance");
        } else {
            pr::Doc::detail("This team performed horribly. Sponsor is dissatisfied. \nBudget decreases");
            budget -= (int) ((double) budget * 0.1);
        }
        if (budget > 100) budget = 100;
        if (budget < 0) budget = 10;
    }
    pr::Doc::summary("The team has been allocated a budget of " + to_string(budget) + "\n");
}



// =========================== MEDIATOR ===========================

//TODO : Strategy for using windTunnel;
void Logistics::sendCarToFactory(std::vector<eng::Car *> cars, Race *r) {
    for (eng::Car *c: cars) {
        transportManager->transport(r, nullptr, c);
        callEngDept()->carArrivesAtFactory(c);
        callEngDept()->improveCar(c->getId(), true);
    }
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
        if (tyreOrder[i] != 0) {
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





