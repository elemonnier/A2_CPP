//
// Created by upupu on 19/12/2019.
//

#ifndef TP8_GASVEHICLE_H
#define TP8_GASVEHICLE_H

#include <iostream>
#include "Vehicle.h"
#include "cmath"

using namespace std;

class GasVehicle : public Vehicle {
private:
    int octaneRate;
public:
    int getOctaneRate();

    void setOctaneRate(int);

    ~GasVehicle();

    GasVehicle(Point, string, float, float, int);

    void affichage1();

    void affichage2();

    GasVehicle(GasVehicle const& gv);
};

int GasVehicle::getOctaneRate() {
    return this->octaneRate;
}

void GasVehicle::setOctaneRate(int oct) {
    this->octaneRate = oct;
}

GasVehicle::~GasVehicle() {
    cout << "GasVehicle::~GasVehicle() : " << this << endl;
}

GasVehicle::GasVehicle(Point p, string id, float carburant, float consommation, int oct) : Vehicle(p, id, carburant, consommation)  {
    cout << "GasVehicle::GasVehicle() : " << this << endl;
    this->octaneRate = oct;
}

void GasVehicle::affichage1() {
    print();
    cout << " octane rating: " << octaneRate << endl;
}

void GasVehicle::affichage2() {
    std::cout << "[" << getId() << "] (" << getPosition().getX() << "," << getPosition().getY() << ") consumption: " << consumption << " fuel left: " << fuel << " octane rating: " << octaneRate << endl;
}

GasVehicle::GasVehicle(GasVehicle const &gv) : Vehicle(gv) {
    cout << "GasVehicle::GasVehicle(GasVehicle const &gv) : " << this << endl;
    setOctaneRate(gv.octaneRate);
}

#endif //TP8_GASVEHICLE_H