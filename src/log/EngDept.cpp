//
// Created by jo on 2020/10/17.
//

#include "EngDept.h"
#include <iostream>

EngDept::~EngDept() {}

void EngDept::HireEmployees(int budget) {
    std::cout << "Hiring Employees" << endl;
}

int EngDept::buildCar(int budget, RiskLevel) {
    std::cout << "build car" << endl;
    return 2;
}

void EngDept::carArrivesAtFactory(eng::Car *) {
    std::cout << "car arrives at factory" << endl;
}

void EngDept::improveCar(int id) {
    std::cout << "improve Car" << endl;
}

void EngDept::updateCar(int id) {
    std::cout << "update Car" << endl;
}

eng::Car *EngDept::checkCarOutOfFactory(int id) {
    std::cout << "Hiring Employees" << endl;
    return new eng::Car;
}

void EngDept::fixCar(int id) {
    std::cout << "Improve Car" << endl;

}
