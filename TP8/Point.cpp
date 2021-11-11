//
// Created by upupu on 05/12/2019.
//

#include "Point.h"

Point::Point(double x, double y) {
    setX(x);
    setY(y);
}

Point::Point(Point const &P) {
    setX(P.x);
    setY(P.y);
}

double Point::getX() {
    return this->x;
}

double Point::getY() {
    return this->y;
}

void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}