//
// Created by upupu on 29/11/2019.
//

#ifndef TP5_RATIONAL_H
#define TP5_RATIONAL_H


class Rational {
private:
    int numerator;
    int denominator;
    int pgcd(int, int);
    int ppcm(int, int);
public:
    void setNumerator(int);
    void setDenominator(int);
    int getNumerator(int);
    int getDenominator(int);

};


#endif //TP5_RATIONAL_H
