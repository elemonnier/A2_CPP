//
// Created by upupu on 19/12/2019.
//

#ifndef TP8_VEHICLE_H
#define TP8_VEHICLE_H

#include <string>
#include "Point.h"

using namespace std;

class Vehicle {
private:
    string id;
    Point position;
protected:
    float fuel;
    float consumption;
public:
    void setId(string&);
    string getId();
    void setPosition(Point);
    Point getPosition();
    ~Vehicle();
    Vehicle(Point, string, float, float);
    void print();
    float moveTo(double, double);
};

#endif //TP8_VEHICLE_H
