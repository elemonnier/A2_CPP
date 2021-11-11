//
// Created by upupu on 24/01/2020.
//

#ifndef TP10_OBSERVER_H
#define TP10_OBSERVER_H


#include "ObservablePoint.h"

class Observer {
public:
    void update(shared_ptr<ObservablePoint>);
};


#endif //TP10_OBSERVER_H
