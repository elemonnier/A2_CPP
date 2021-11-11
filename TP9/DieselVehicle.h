//
// Created by upupu on 19/12/2019.
//

#ifndef TP8_DIESELVEHICLE_H
#define TP8_DIESELVEHICLE_H


#include <iostream>
#include "Vehicle.h"

using namespace std;

class DieselVehicle : public Vehicle {
private:
    bool filtreAParticules;
public:
    bool getFiltreAParticules();

    void setFiltreAParticules(bool);

    virtual ~DieselVehicle();

    DieselVehicle(Point, string, float, float, bool);

    void affichage1();

    void affichage2();

    DieselVehicle(DieselVehicle const& dv);
};

bool DieselVehicle::getFiltreAParticules() {
    return this->filtreAParticules;
}

void DieselVehicle::setFiltreAParticules(bool fap) {
    this->filtreAParticules = fap;
}

DieselVehicle::~DieselVehicle() {
    cout << "DieselVehicle::~DieselVehicle() : " << this << endl;
}

DieselVehicle::DieselVehicle(Point p, string id, float carburant, float consommation, bool fap) : Vehicle(p, id, carburant, consommation) {
    cout << "DieselVehicle::DieselVehicle() : " << this << endl;
    filtreAParticules = fap;
}

void DieselVehicle::affichage1() {
    print();
    std::cout << " filter: " << (filtreAParticules ? "yes" : "no") << endl;
}

void DieselVehicle::affichage2() { // todo sans se servir des getters, c'est normalement censé hériter de Vehicle ?
    std::cout << "[" << getId() << "] (" << getPosition().x << "," << getPosition().getY() << ") consumption: " << consumption << " fuel left: " << fuel << " filter: " << (filtreAParticules ? "yes" : "no") << endl;
}

DieselVehicle::DieselVehicle(DieselVehicle const &dv) : Vehicle(dv) {
    cout << "DieselVehicle::DieselVehicle(DieselVehicle const &dv) : " << this << endl;
    setFiltreAParticules(dv.filtreAParticules);
}

#endif //TP8_DIESELVEHICLE_H