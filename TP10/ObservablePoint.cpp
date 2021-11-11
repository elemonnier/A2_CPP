//
// Created by upupu on 24/01/2020.
//

#include "ObservablePoint.h"

float ObservablePoint::moveTo(float x, float y) {
    float distance = sqrt(pow((getX()-x),2) + pow((getY()-y),2));
    setX(x);
    setY(y);
    return distance;
}

void ObservablePoint::addObserver(shared_ptr<Observer>) {

}

void ObservablePoint::notifyObservers() {

}
