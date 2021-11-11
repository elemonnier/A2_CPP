//
// Created by upupu on 24/01/2020.
//

#ifndef TP10_POINTOBSERVER2_H
#define TP10_POINTOBSERVER2_H


#include "Observer.h"

class PointObserver2 : public Observer {
public:
    void update(shared_ptr<ObservablePoint>);
};


#endif //TP10_POINTOBSERVER2_H



// TODO moveTo(-) -> notifyObservers() -> update (-)