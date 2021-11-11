//
// Created by upupu on 19/12/2019.
//

#include "Vehicle.h"
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void Vehicle::setId(string& s) {
    this->id = s;
}

string Vehicle::getId() {
    return this->id;
}

void Vehicle::setPosition(Point p) {
    this->position = p;
}

Point Vehicle::getPosition() {
    return this->position;
}

Vehicle::~Vehicle() {
    cout << "Vehicle::~Vehicle() : " << this << endl;
}

Vehicle::Vehicle(Point P, string id, float fuel, float consumption) : position(P.getX(), P.getY()) {
    cout << "Vehicle::Vehicle() : " << this << endl;
    this->id = id;
    this->fuel = fuel;
    this->consumption = consumption;
}

void Vehicle::print() {
    std::cout << "[" << id << "] (" << position.getX() << "," << position.getY() << ") consumption: " << consumption << " fuel left: " << fuel;
}

float Vehicle::moveTo(double x, double y) {
    float distance = sqrt(pow((position.getX()-x),2) + pow((position.getY()-y),2));
    float neededFuel = distance*consumption/100;
    if (neededFuel <= fuel) {
        position.setX(x);
        position.setY(y);
        fuel -= neededFuel;
        return distance;
    }
    else {
        cout << "Error: vehicle does not have enough fuel!" << endl;
        float ratio = fuel / neededFuel;
        if (position.getX() >= x){
            position.setX(-ratio*(position.getX()-x)+position.getX());
        }
        else {
            position.setX(ratio*(x-position.getX())+position.getX());
        }
        if (position.getY() >= y){
            position.setY(-ratio*(position.getY()-y)+position.getY());
        }
        else {
            position.setY(ratio*(y-position.getY())+position.getY());
        }
        fuel = 0;
        return distance * ratio;
    }
}