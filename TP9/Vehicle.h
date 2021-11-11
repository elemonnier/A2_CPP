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
    void setId(string &);

    string getId();

    void setPosition(Point);

    Point getPosition();

    virtual ~Vehicle(); // todo j'ai du mal à comprendre le virtual // que signifie upcast ?

    Vehicle(Point, string, float, float);

    void print();

    float moveTo(double, double);

    Vehicle(Vehicle const &v);
};

#endif //TP8_VEHICLE_H
