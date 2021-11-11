#include <iostream>
#include "Point.h"
#include "Vehicle.h"
using namespace std;

void vehiculeIdTest() {
    Point position(0,10);
    char identifier[] = "ML-888-VK";
    Vehicle vehicle(identifier, position);
    vehicle.print(); // affichage 1
}

void vehiculeIdTest2() {
    Point position(0,10);
    char identifier[] = "ML-888-VK";
    Vehicle vehicle(identifier, position);
    vehicle.print(); // affichage 1
    identifier[0] = 'X';
    vehicle.print(); // affichage 2
}

void vehiculeCopyTest(){ // todo demander prof probleme de abort
    char str[10] = "JK-857-FA";
    Vehicle v1(str, Point(0,0));
    Vehicle v2;
    char id[4] = "XXX";
    v1.setIdentifier(id);
    v1.print();
    v2.print();
}

void vehicleMoveTests(){
    char s1[10] = "JK-857-FA";
    char s2[10] = "ML-888-VK";
    Vehicle v1(s1, Point(0,0));
    Vehicle v2(s2, Point(0,10));

    Point p = v1.getPosition();
    float distance = 0;

    distance = v1.moveTo(v2);
    std::cout << "distance : " << distance << std::endl; // affichage 1
    v1.print(); // affichage 2

    p.setY(50);
    std::cout << p.getY();
    v1.print(); // affichage 3
    distance = v1.moveTo(p);

    std::cout << "distance : " << distance << std::endl; // affichage 4
    v1.print(); // affichage 5
    distance = v1.moveTo(0, 80);

    std::cout << "distance : " << distance << std::endl; // affichage 6
    v1.print(); // affichage 7
    v2.print(); // affichage 8
}


int main() {
    vehiculeIdTest();
    cout << endl;
    vehiculeIdTest2();
    cout << endl;
    vehiculeCopyTest();
    cout << endl;
    vehicleMoveTests();
    return 0;
}