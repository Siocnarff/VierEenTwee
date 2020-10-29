//
// Created by jo on 2020/10/09.
//

#include "transportation/Fly.h"
#include "transportation/Ship.h"
#include "transportation/Road.h"
#include "Logistics.h"
#include "RacesList.h"
#include "log/races/Aggregate.h"

#include <fstream>
#include <sstream>


using namespace log;

/**
 * @author Jo
 * @status Done
 */
Logistics::Logistics() {

    driver = nullptr;
    transportManager = nullptr;
    raceIterator = nullptr;
    racingCalendar = nullptr;
    europeanContainer = nullptr;
    currentTeamStrategy = nullptr;
    seasonPointTally = -1;
    budget = -1;
}

/**
 * @author Jo
 * @status done
 */
void Logistics::registerNotifier(Colleague *colleague) {
    auto* temp = new RacingDept;
    if (typeid(*temp) == typeid(*colleague)){
        departments.insert(std::pair<char,Colleague*>('r',colleague));
    } else {
        departments.insert(std::pair<char,Colleague*>('e',colleague));
    }
    colleague->addObserver(this);

}

/**
 * @author Jo
 * @status nearly there
 */
void Logistics::putRacesIntoCalender() {
    // TODO : File path hard-coded. Needs to change
    racingCalendar = new RacesList;

    try{
        std::ifstream infile;
        infile.open("/home/jo-anne/Documents/VierEenTwee/src/log/races/raceData.txt");
        //infile.open("src/log/races/raceData.txt");
        int numRaces;
        infile >> numRaces;

        std::string name; int complexity; bool inEurope; int laps;
        getline(infile, name); //to remove first random /n
        for (int i = 0; i < numRaces; ++i) {
            std::getline(infile, name);
            infile >> complexity;
            infile >> inEurope;
            infile >> laps;
            Race* newRace = new Race(name, complexity, inEurope, laps);
            racingCalendar->addRace(newRace);
            getline(infile, name); //to remove first random /n
        }
        infile.close();
    } catch(std::ifstream::failure e){ //exception e
        std::cout << "There was a file-reading error !\n";
    }

    if (verbose) {
        racingCalendar->printList();
    }

}


/**
 * @author Jo
 * @status done!
 */
void Logistics::doYearPlanning() {
    //1. getBudget from "Sponsors"
    budget = abs(rand()%100+1);
    
    //2. Hire for all departments
    for( auto const& [key, val] : departments )
    {
        val->hireEmployees(budget);
    }
    
    //3. putRacesIntoCalender();
    putRacesIntoCalender();
    
    //4. hire driver
    driver = new ppl::Driver("Fluffy McAllen", 0, 0);
    
    //5. Set home tracks
    for (int i = 0; i < abs(rand()%5)+1; ++i) { //interval [1,5]
        driver->addHomeTrack(abs(rand()% racingCalendar->getNumRaces())); //pick one of number of races
    }

    //6. hire transportManager
    transportManager = new Road();
    transportManager->addAMethod(new Ship);
    transportManager->addAMethod(new Fly);

}


void Logistics::preSeasonPreparation() {
    currentTeamStrategy = callRacingDept()->PlanSeasonStrategy(budget /*+ something else? */ );
    /*as genotify word, sal ons binne notify() die bande bestel;
    print: tyres arrived*/

    //moet meer spesifiek wees hierso.
    //gaan ons van hulle verwag of gaan ons self check dat die driver genoeg xp het?
    //Dalk kan ons dit volgens riskLevel doen
    callRacingDept()->trainDriver(new ppl::Driver("s",0,0), 15, Rainy, Average );

    //order stuff

    //build cars x2
    carsInSeasonIDs.push_back(callEngDept()->buildCar(budget,currentTeamStrategy->getRiskLevel())); //tyres

    /*carsInSeason.push(buildCar()); //ons gaan bou die kar
    testCar();
    getRaceIterator();
    packContainers();*/

}


void Logistics::simulateEvent(Race *r) {
    //get car
    eng::Car* carInTransport = callEngDept()->checkCarOutOfFactory(carsInSeasonIDs[0]);
    //transport car
    transportManager->transport(nullptr, r, carInTransport);

    //get correct container and pre-race arrival
    if (r->isRaceEuropean()) {
        callRacingDept()->preRaceArrival(carInTransport, driver, r, getEuropeanContainer());
    }
    else {
        callRacingDept()->preRaceArrival(carInTransport, driver, r, getNextNonEuropean());
    }
    //racing weekend finishes and get points
    seasonPointTally += callRacingDept()->RacingWeekend();
    //finish the packup
    Container* tCont = callRacingDept()->postRacePackUp(); //execute
}

void Logistics::raceSeason() {

    for (RaceIterator t = racingCalendar->begin(); !(t==racingCalendar->end()) ; ++t) {
        //std::cout << t.currentItem()->getLocation() << std::endl;
        simulateEvent(t.currentItem());
    }
    std::cout << std::endl;

    /* while (iter.hasNext()) {
         * simulateEvent(iter.current); <- this could be a command
         * //we could have raceHandlers(one for European and one for non-European?)
         * iter++;
         */


}

void Logistics::postSeasonDebrief() {
//maybe do some analysis?
    //start building a new car
    //let driver take holiday
    //let transportHandler take holiday

}

void Logistics::sendCarToFactory(eng::Car *car) {
    std::cout << "send car to factory" << std::endl;
    transportManager->transport(new Race, new Race, car);
    callEngDept()->carArrivesAtFactory(car);
    callEngDept()->improveCar(car->getId());
}

void Logistics::containerHasBeenPacked(Container *) {
    std::cout << "fly container" << std::endl;
}

void Logistics::requestContainerStateChange(bool isEuropeanRace) {

}

Container *Logistics::getEuropeanContainer() {
    return europeanContainer;
}

Container *Logistics::getNextNonEuropean() {
    Container* back = nonEuropeanContainers.back();
    nonEuropeanContainers.pop_back();
    return back;
}

void Logistics::packContainers() {
    std::cout << "pack containers" << std::endl;
}

/**
 * @author Jo
 */
RacingDept *Logistics::callRacingDept() {
    return dynamic_cast<RacingDept*>(departments['r']);
}

/**
 * @author Jo
 */
eng::EngTeam *Logistics::callEngDept() {
    return dynamic_cast<eng::EngTeam*>(departments['e']);
}

/**
 * @author Jo
 */
void Logistics::toggleTransparency() {
    verbose = !verbose;

}

void Logistics::informStrategyChanged(rce::Strategy *newStrats) {
    currentTeamStrategy = newStrats;
    callEngDept()->setRiskLevel(currentTeamStrategy->getRiskLevel());
}



