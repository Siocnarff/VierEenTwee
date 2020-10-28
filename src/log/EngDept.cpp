//
// Created by jo on 2020/10/17.
//

#include "EngDept.h"
#include <iostream>

EngDept::~EngDept() {}

void EngDept::HireEmployees(int budget) {
    std::cout << "Hiring Employees" << std::endl;
}

int EngDept::buildCar(int budget, RiskLevel) {
    std::cout << "build car" << std::endl;
    return 2;
}

void EngDept::carArrivesAtFactory(eng::Car *) {
    std::cout << "car arrives at factory" << std::endl;
}

void EngDept::improveCar(int id) {
    std::cout << "improve Car" << std::endl;
}

void EngDept::updateCar(int id) {
    std::cout << "update Car" << std::endl;
}

eng::Car *EngDept::checkCarOutOfFactory(int id) {
    std::cout << "Hiring Employees" << std::endl;
    return new eng::Car;
}

void EngDept::fixCar(int id) {
    std::cout << "Improve Car" << std::endl;

}
