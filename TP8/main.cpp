#include <iostream>
#include "Point.h"
#include "DieselVehicle.h"
#include "GasVehicle.h"

void displayTests1(){
    Vehicle vehicle(Point(5,6), "CC-987-JU", 50, 5.3);
    vehicle.print();

    GasVehicle GasVehicle(Point(25,3), "XY-358-PQ", 60, 6.8, 95);

    DieselVehicle dieselVehicle(Point(2,10), "HD-888-ZY", 40, 5.5, true);
}

void includeGasVehicle(){ // todo comment accéder à fuel et consumption sans getters
    GasVehicle gv(Point(42,69), "AX-437-ZB", 42, 6.9, 100);

//    cout << gv.getId() << "\t" << gv.position.getX() << "\t" << gv.getPosition().getY() << "\t" << gv.fuel << "\t" << gv.getConsumption() << "\t" << gv.getOctaneRate() << endl;
}

void displayTests2(){
    Vehicle vehicle(Point(5,6), "CC-987-JU", 50, 5.3);
    vehicle.print();
    cout << endl;

    GasVehicle gasVehicle(Point(25,3), "XY-358-PQ", 60, 6.8, 95);
    gasVehicle.affichage1();
    gasVehicle.affichage2();

    DieselVehicle dieselVehicle(Point(2,10), "HD-888-ZY", 40, 5.5, true);
    dieselVehicle.affichage1();
    dieselVehicle.affichage2();
}

void consumptionTests(){
    DieselVehicle dieselVehicle(Point(2,10), "XY-358-PQ", 8, 5, false);
    cout << "*******" << endl;
    float traveletDist1 = dieselVehicle.moveTo(0, 100);
    std::cout << "Traveled distance: " << traveletDist1 << std::endl;
    dieselVehicle.print();
    cout << endl;
    cout << "*******" << endl;
    float traveletDist2 = dieselVehicle.moveTo(0, 200);
    std::cout << "Traveled distance : " << traveletDist2 << std::endl;
    dieselVehicle.print();
    cout << endl;
}

int main() {
    cout << "--------------------------------------------------------------\n";
    displayTests1();
    cout << "--------------------------------------------------------------\n";
    includeGasVehicle();
    cout << "--------------------------------------------------------------\n";
    displayTests2();
    cout << "--------------------------------------------------------------\n";
    consumptionTests();
    cout << "--------------------------------------------------------------";
    return 0;
}