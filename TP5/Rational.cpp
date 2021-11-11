//
// Created by upupu on 29/11/2019.
//

#include "Rational.h"

int Rational::pgcd(int a, int b) {
    if (a == b){
        return a;
    }
    return Rational::pgcd(b, a-b);
}

int Rational::ppcm(int, int) {
    return 0;
}

void Rational::setNumerator(int) {

}

void Rational::setDenominator(int) {

}

int Rational::getNumerator(int) {
    return 0;
}

int Rational::getDenominator(int) {
    return 0;
}
