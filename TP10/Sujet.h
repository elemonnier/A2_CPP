//
// Created by upupu on 23/01/2020.
//

#ifndef TP10_SUJET_H
#define TP10_SUJET_H

#include <iostream>
#include <vector>
#include <memory>

#include "Observateur.h"

using namespace std;

class Sujet {
protected:
    vector<unique_ptr<Observateur>> Observateurs;
public:
    virtual void ajouterObservateur(unique_ptr<Observateur>)=0;
    virtual void notifierObservateurs()=0;
};

#endif //TP10_SUJET_H