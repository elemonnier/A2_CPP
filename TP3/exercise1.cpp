#include "exercise1.h"
#include <iostream>
#include <cmath>
using namespace std;

/// Point's methods:

double Point::distance(Point P) {
    return sqrt((x - P.x) * (x - P.x) + (y - P.y) * (y - P.y));
}

Point Point::midpoint(Point P) {
    auto milieu = new Point;
    milieu->x = ((P.x + x)/2);
    milieu->y = ((P.y + y)/2);
    return *milieu;
}

void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

double Point::getX() {
    return this->x;
}

double Point::getY() {
    return this->y;
}

void Point::enter() {
    double tmpX, tmpY;
    cout << "Enter the coordinates: \nX: ";
    cin >> tmpX;
    setX(tmpX);
    cout << "Y: ";
    cin >> tmpY;
    setY(tmpY);
}

void Point::display() {
    cout << "Coordinates are: (" << getX() << " , " << getY() << ")\n";
}

Point::Point() {
    setX(0);
    setY(0);
}

Point::Point(double x){
    setX(x);
    setY(2*x);
}

Point::Point(double x, double y) : setX(x), setY(y)
{}