//
// Created by jo on 2020/10/09.
//

#include "transportation/Fly.h"
#include "transportation/Ship.h"
#include "transportation/Road.h"
#include "Logistics.h"
#include "RacesList.h"

#include "log/races/Aggregate.h"

using namespace log;

/**
 * @author Berné
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
 * @author Berné
 * @status done
 */
void Logistics::registerNotifier(Colleague *colleague) {
    auto* temp = new RacingDept;
    if (typeid(*temp) == typeid(*colleague)){
        departments.insert(pair<char,Colleague*>('r',colleague));
    } else {
        departments.insert(pair<char,Colleague*>('e',colleague));
    }
    colleague->addObserver(this);

}

/*
Race Template:
#races
RaceName as a string
TrackComplexity as int in [0,3]
InEurope as int in [0,1]
Numbers of laps (int)
Lyne 2-4 sal herhaal word vir die #races
*/

#include <fstream>
#include <sstream>

/**
 * ERROR! FILE PATH HARD CODED
 */
void Logistics::putRacesIntoCalender() {
    racingCalendar = new RacesList;

    try{
        std::ifstream infile;
        infile.open("/home/jo-anne/Documents/VierEenTwee/src/log/races/raceData.txt");
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
        cout << "There was a file-reading error !\n";
    }

    racingCalendar->printList();


}


/**
 * @author Berné
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
    /*depts[0] -> planSeasonStrategy(); //of wil ons chain gebruik hierso
    as genotify word, sal ons binne notify() die bande bestel;
    print: tyres arrived*/

    callRacingDept()->trainDriver(new ppl::Driver("s",0,0), 15, Rainy, Average );
    //order

//    cout <<"Debugging" << endl;
//    cout << "-------------------" << endl;

    carsInSeasonIDs.push_back(callEngDept()->buildCar(budget,currentTeamStrategy->getRiskLevel())); //tyres   -> iets fout met hierdie funksie?
    /*carsInSeason.push(buildCar()); //ons gaan bou die kar
    testCar();
    getRaceIterator();
    packContainers();*/

}

void Logistics::raceSeason() {
    /* while (iter.hasNext()) {
         * simulateEvent(iter.current); <- this could be a command
         * //we could have raceHandlers(one for European and one for non-European?)
         * iter++;
         */
    //2 cars
    callRacingDept()->preRaceArrival(new eng::Car, driver, new Race, new Container);
    //
    seasonPointTally += callRacingDept()->RacingWeekend();
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
    cout << "pack containers" << endl;
}

void Logistics::SimulateEvent(Race *) {
    //callRacingDept;
}

/**
 * @author Berné
 */
RacingDept *Logistics::callRacingDept() {
    return dynamic_cast<RacingDept*>(departments['r']);
}

/**
 * @author Berné
 */
eng::EngTeam *Logistics::callEngDept() {
    return dynamic_cast<eng::EngTeam*>(departments['e']);
}



