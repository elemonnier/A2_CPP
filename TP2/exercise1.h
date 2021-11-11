#include <iostream>
#include <cmath>

#ifndef TP2_EXERCISES_H
#define TP2_EXERCISES_H

class Equation {
private:
    double a, b, c;
public:
    void set();
    void solveEquation(double &r1, double &r2);
    void displayEquation();
    double calculateImage(double x);
    double geta();
    double getb();
    double getc();
};

#endif