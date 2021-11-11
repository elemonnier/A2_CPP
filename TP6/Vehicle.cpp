//
// Created by upupu on 05/12/2019.
//

#include <cstring>
#include <cmath>
#include <iostream>
#include "Vehicle.h"

Vehicle::Vehicle() : position(0, 0) {
    identifier = new char[10 * sizeof(char)];
    strcpy(identifier, "");
}

Vehicle::Vehicle(char *id, Point P) : position(P.getX(), P.getY()) {
    identifier = new char[10 * sizeof(char)];
    strcpy(identifier, id);
}

Vehicle::~Vehicle() {
}

Vehicle::Vehicle(Vehicle const &v) : position(v.position) {
    identifier = new char[10 * sizeof(char)];
    strcpy(identifier, v.identifier);
}

const char *Vehicle::getIdentifier() {
    return this->identifier;
}

Point Vehicle::getPosition() {
    return this->position;
}

void Vehicle::setIdentifier(char *identifier) {
    this->identifier = identifier;
}

void Vehicle::setPosition(Point position) {
    this->position = position;
}

float Vehicle::moveTo(Point p) {
    float distance = sqrt(pow((position.getX()-p.getX()),2) + pow((position.getY()-p.getY()),2));
    position.setX(p.getX());
    position.setY(p.getY());
    return distance;
}

float Vehicle::moveTo(Vehicle v){
    float distance = sqrt(pow((position.getX()-v.position.getX()),2) + pow((position.getY()-v.position.getY()),2));
    position.setX(v.position.getX());
    position.setY(v.position.getY());
    return distance;
}

float Vehicle::moveTo(double x, double y) {
    float distance = sqrt(pow((position.getX()-x),2) + pow((position.getY()-y),2));
    position.setX(x);
    position.setY(y);
    return distance;
}

void Vehicle::print(){
    std::cout << "[" << identifier << "] (" << position.getX() << "," << position.getY() << ")";
}

void Vehicle::reset() {
    position.setX(0);
    position.setY(0);
}

