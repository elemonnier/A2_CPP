//
// Created by upupu on 05/12/2019.
//

#ifndef TP6_VEHICLE_H
#define TP6_VEHICLE_H


#include "Point.h"

class Vehicle {
private:
    char *identifier;
    Point position;
public:
    Vehicle();

    Vehicle(char*, Point);

    ~Vehicle();

    Vehicle(Vehicle const &v);

    const char *getIdentifier();

    Point getPosition();

    void setIdentifier(char *);

    void setPosition(Point);

    float moveTo(Point);

    float moveTo(Vehicle);

    float moveTo(double, double);

    void print();

    void reset();
};

#endif //TP6_VEHICLE_H
