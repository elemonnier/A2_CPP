//
// Created by upupu on 23/01/2020.
//

#ifndef TP10_AGRICULTEUR_H
#define TP10_AGRICULTEUR_H


#include "Observateur.h"

class Agriculteur : public Observateur {
private:
    int id;
public:
    virtual void notifierObservateur();
};



#endif //TP10_AGRICULTEUR_H
