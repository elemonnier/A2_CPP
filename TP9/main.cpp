#include <iostream>
#include <vector>
#include "Point.h"
#include "DieselVehicle.h"
#include "GasVehicle.h"

void gasVehicleCopyTest(){
    GasVehicle original(Point(25,3), "XY-358-PQ", 60, 6.8, 95);
    GasVehicle copy = original;
    string a = "XXX";
    original.setId(a);
    original.print();
    cout << "\n";
    copy.print();
    cout << "\n";
}

void dieselVehicleDestructionTest() {
    DieselVehicle* dieselVehicle = new DieselVehicle(Point(2, 10), "HD-888-ZY", 40, 5.5, true);
    Vehicle* vehicle = dieselVehicle; // upcast
    delete vehicle;
}

void octaneRatingConsumptionTests() {
    GasVehicle gasVehicle95(Point(0, 0), "XY-358-PQ", 30, 5, 95);
    gasVehicle95.affichage2();
    cout << "Traveled distance : " << gasVehicle95.moveTo(0, 100) << endl;
    gasVehicle95.affichage2();
    GasVehicle gasVehicle98(Point(0,0), "HD-888-ZY", 30, 5, 98);
    gasVehicle98.affichage2();
    cout << "Traveled distance : " << gasVehicle98.moveTo(0, 100) << endl;
    gasVehicle98.affichage2();
}

void octaneRatingConsumptionTestsWithUpcast(const vector<Vehicle*>& vehicles){
    for (vector<Vehicle*>::iterator it = vehicles.begin(); it != vehicles.end(); it++){

    }
}

void octaneRatingConsumptionTestsWithUpcast(){
    GasVehicle gasVehicle95(Point(0,0), "XY-358-PQ", 30, 5, 95);
    GasVehicle gasVehicle98(Point(0,0), "HD-888-ZY", 30, 5, 98);
    vector<Vehicle*> vehicles = { &gasVehicle95, &gasVehicle98 };
    octaneRatingConsumptionTestsWithUpcast(vehicles);
}

int main() {
    gasVehicleCopyTest();
    cout << "---------------------------------------------------------\n";
    dieselVehicleDestructionTest();
    cout << "---------------------------------------------------------\n";
    octaneRatingConsumptionTests();
    cout << "---------------------------------------------------------\n";

    return 0;
}