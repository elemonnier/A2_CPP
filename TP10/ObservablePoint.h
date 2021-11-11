//
// Created by upupu on 24/01/2020.
//

#ifndef TP10_OBSERVABLEPOINT_H
#define TP10_OBSERVABLEPOINT_H

#include <memory>
#include "Observer.h"
#include "Subject.h"
#include "Point.h"

using namespace std;

class ObservablePoint : public Point, public Subject {
public:
    void addObserver(shared_ptr<Observer>);
    void notifyObservers();
    float moveTo(float, float);
};


#endif //TP10_OBSERVABLEPOINT_H
