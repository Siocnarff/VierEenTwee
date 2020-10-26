//
// Created by jo on 2020/10/17.
//

#ifndef PREMODELLING_ENUMS_H
#define PREMODELLING_ENUMS_H

enum RiskLevel{Safe, Moderate, Aggressive};
enum WeatherConditions{Wet, Dry, Rainy};
enum TyresCompounds{Soft, Medium, Hard};
enum TrackComplexity{Easy, Average, Difficult, Extreme};

#endif //PREMODELLING_ENUMS_H


//LOOOOOOOOOOOOOOOOOOOOSE STUFF

/*class Colleague {
private:
    Logistics* observeringLogisticsDept;
public:
    virtual void registerForSeason(Logistics* observer) {
        observeringLogisticsDept = observer;
    };
    //virtual void notify(Car*, TyresCompounds ); //pre-Season strategy planned
    //virtual void notify(Car*, Driver*, Container*); //postRacePackup
    virtual void HireEmployees(int budget) = 0;// die groot indiensnemingsproses
    virtual void requestContainerChangeState(bool EuropeanRace) { //type of notify
        if (EuropeanRace) {
            Container* temp = observeringLogisticsDept->getEuropeanContainer();
            //temp.changeState();
        }
        else {
            Container* temp = observeringLogisticsDept->getNextNonEuropeanContainer();
            //temp.advanceState();
        }
    };
};*/

//eintlik nie nodig om Mediator te he nie




/*class RacingDept : public Colleague {
public:
    void registerForSeason(Logistics* logisticsDept){

    };
//    void deregisterForSeason(Logistics *) override;
    //void notify(Car *, Driver *, Container *) override;
    //void notify(Car *, TyresCompounds) override;
    void HireEmployees(int budget) override{

    };// die groot indiensnemingsproses
    Strategy* PlanSeasonStrategy(int budget){

    };
    *//*Hierdie is soos die pre-season, oorhoofse, "this is the plan, guys" strategie.
     Hy kan verfyn word met elke resies as julle wil en ons dan net notify(tyres, riskLevel) soos julle goed dink.
     Wat julle wel hierso moet doen vir ons is om een van die drie tyreCompound tipes te kies (en te stoor) en dan ook vir ons die riskLevel te kies.
     Ons gaan die riskLevel en tyreCompounds kies om met die EngDept te werk, so sal julle ons notify() asb?*/
/*
Driver* trainDriver(Driver*){

};
//vir sy XP om te verander. Ons gaan dit pre-season roep en dan kan julle dit weer in die season roep as julle wil?
void preRaceArrival(Car*, Driver*, Race*, Container*){

};
*//*gaan julle qualify() hierso geroep word? Of moet ons dit self roep.
    Sal julle asb ook hier net ons container "unpack"?
    En dan kan julle weer train of strategise of enigiets anders doen wat julle wil.*/
/*
int RacingWeekend(){

};//ons wil net die punt terughê hierso. Ek verstaan Leaderboard nog nie mooi nie, maar dalk stuur julle dit eerder terug? Stry maar. Sover ons verstaan gaan julle die HELE race in dié funskie simuleer, right?
void postRacePackUp(){

};
*//* eintlik wil ons net hê dat julle hier cout << "Container being packed" en om sy state te verander.
    Dan wil ons die Car, Drywer en Container terughê deurdat julle ons notify(), as julle kyk na ons UML.
    *//*


};*/


/*class EngDept: public Colleague {
public:
    void registerForSeason(Logistics* logisticsDept);
//    void deregisterForSeason(Logistics *) override;
    //void notify(Car *, Driver *, Container *) override;
    //void notify(Car *, TyresCompounds) override;
    void HireEmployees(int budget) override;
    //julle registreer net dat julle saam met ons werk, sodat julle ons kan notify wanneer julle klaar is. Hierdie sal in main geroep word, dink ek.
    int buildCar(int budget, RiskLevel); //julle return die id van die kar wat julle gebou het
    void carArrivesAtFactory(Car*); //om in garage te sit en sodat ons met hom kan werk
    void testCar(int id);
    void fixCar(int id); //die kar sal altyd klaar in storage wees as ons hom wil toets. en dus ook dan:
    void updateCar(int id);
    Car* checkCarOutOfFactory(int id); //remove from storage and cout<<"Flying car out of factory"

};*/




/*class Iterator {
public:
    virtual void first() = 0;
    virtual void operator ++() = 0; //virtual void next() = 0;
    virtual void operator --() = 0;//virtual void prev() = 0;
    virtual bool isLast() = 0;
    virtual Iterator* currentItem()  = 0;
};
class RaceIterator: public Iterator {
public:
    void first() override;
    virtual void operator ++() override;//void next() override;
    virtual void operator --() override;//void prev() override;
    bool isLast() override;
    RaceIterator * currentItem() override;
};


class Aggregate {
public:
    virtual Iterator* createIterator() = 0;
};
class RacesList : public Aggregate {
public:
    RaceIterator* createIterator() override;
    void addRace(Race* );
    Race* removeRace();
    bool isEmpty();
    RaceIterator* begin();
    RaceIterator* end();

private:
    Race* firstRaceOfSeason; //ie. head
};*/





/*class Command {
public:
    virtual void execute() = 0;
};
class buildCar: public Command {
private:
    int budget;
    int riskLevel;
    TyresCompounds tyres;
public:
    buildCar(int, int ,TyresCompounds);
    //Buildacar (budget, riskLevel,  tyres = 0)
    void execute() override;
};

class testCar : public Command {
    int riskLevel;
    Car* car;
public:
    testCar(int, Car*);
    void execute() override;
};

class updateCar : public Command {
private:
    int riskLevel;
    Car* car;
public:
    updateCar(int, Car*);
    void execute() override;
};

class fixCar : public Command {
private:
    Car* car;
public:
    fixCar(Car*);
    void execute() override;
};

//to be called pre-season
class createStrategy: public Command {
private:
    int budget;
    int riskLevel;
public:
    createStrategy(int , int);
    void execute() override;
};

class trainDriver : public Command {
private:
    Driver* driver;
public:
    trainDriver(Driver* );
    void execute() override;
};

class racingWeekend : public Command {
private:
    Car* car;
    Driver* driver;
    Container* container;
    Race* race;
public:
    racingWeekend(Car*, Driver*, Container*, Race*);
    void execute() override;
};

//to be called during season
class change_improveStrategy : public Command {
public:
    change_improveStrategy();
    void execute() override;
};
*/

/*class Car{
private:
    *//*int speed;
    int handling;
    int damage;
    Driver* driver;
    int id;*//*
public:
  *//*  int getSpeed();
    int getHandling();
    int getDamage();
    void setDamage(int);
    Driver* getDriver;
    void removeDriver(Driver*);     //remove and replace with null
    void print();
    int getDriverXP();
    bool driverInCar();
    int getID();*//*
};*/