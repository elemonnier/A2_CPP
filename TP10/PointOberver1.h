//
// Created by upupu on 24/01/2020.
//

#ifndef TP10_POINTOBERVER1_H
#define TP10_POINTOBERVER1_H


#include "Observer.h"
#include "ObservablePoint.h"

class PointOberver1 : public Observer {
public:
    void update(shared_ptr<ObservablePoint>);
};


#endif //TP10_POINTOBERVER1_H
