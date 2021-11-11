//
// Created by upupu on 23/01/2020.
//

#ifndef TP10_STATIONMETEO_H
#define TP10_STATIONMETEO_H


#include "Sujet.h"

class StationMeteo : public Sujet{
private:
    float temperature;
public:
    void ajouterObservateur(unique_ptr<Observateur>);
    void notifierObservateurs();
    void setTemperature(float);
};


#endif //TP10_STATIONMETEO_H
