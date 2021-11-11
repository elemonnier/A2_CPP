//
// Created by upupu on 05/12/2019.
//

#include "Point.h"

Point::Point(float x, float y) {
    setX(x);
    setY(y);
}

Point::Point(Point const &P) {
    setX(P.x);
    setY(P.y);
}

float Point::getX() {
    return this->x;
}

float Point::getY() {
    return this->y;
}

void Point::setX(float x) {
    this->x = x;
}

void Point::setY(float y) {
    this->y = y;
}

void Point::moveTo(float x, float y) {
    Point(x, y); //todo pas sur de cela
}