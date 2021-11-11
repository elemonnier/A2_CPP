#include <iostream>
#include <cmath>
using namespace std;

#ifndef TP2_EXERCISE2_H
#define TP2_EXERCISE2_H

class Point {
private:
    double x, y;
public:
    double distance(Point P);
    Point milieu(Point P);
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
    void saisir();
    void afficher();
};

class Point1 {
private:
    double x, y;
public:
    double distanceDyn(Point1 P);
    Point1 milieuDyn(Point1 P);
    void setXdyn(double x);
    void setYdyn(double y);
    double getXdyn();
    double getYdyn();
    void saisirDyn();
    void afficherDyn();
};

#endif