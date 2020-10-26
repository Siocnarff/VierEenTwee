//
// Created by jo on 2020/10/17.
//

#include "EngDept.h"

EngDept::~EngDept() {}

void EngDept::HireEmployees(int budget) {
    cout << "Hiring Employees" << endl;
}

int EngDept::buildCar(int budget, RiskLevel) {
    cout << "build car" << endl;
    return 2;
}

void EngDept::carArrivesAtFactory(Car *) {
    cout << "car arrives at factory" << endl;
}

void EngDept::improveCar(int id) {
    cout << "improve Car" << endl;
}

void EngDept::updateCar(int id) {
    cout << "update Car" << endl;
}

Car *EngDept::checkCarOutOfFactory(int id) {
    cout << "Hiring Employees" << endl;
    return new Car;
}

void EngDept::fixCar(int id) {
    cout << "Improve Car" << endl;

}
