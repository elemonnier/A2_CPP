#include "exercise1.h"
using namespace std;

void Equation::set() {
    double a, b, c;
    cout << "Enter three integers: ";
    cin >> a;
    cin >> b;
    cin >> c;
    if (a != 0){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    else {
        cout << "Error: the equation is not quadratic !";
    }
}

void Equation::solveEquation(double &r1, double &r2) {
    if (b * b - 4 * a * c > 0){
        r1 = (- b - sqrt(b * b - 4 * a * c)) / (2 * a);
        r2 = (- b + sqrt(b * b - 4 * a * c)) / (2 * a);
        cout << "Solutions are: " << r1 << " and " << r2 << endl;
    }
    else {
        if (b * b - 4 * a * c == 0) {
            r1 = -b / 2 * a;
            r2 = r1;
            cout << "The unique solution is: " << r1 << endl;
        }
        else {
            cout << "Error: discriminant is negative !" << endl;
        }
    }
}

void Equation::displayEquation() {
    cout << "The equation is: " << a << "x² + " << b << "x + " << c << endl;
}

double Equation::calculateImage(double x) {
    return a * x * x + b * x + c;
}

double Equation::geta() {
    return this->a;
}

double Equation::getb() {
    return this->b;
}

double Equation::getc() {
    return this->c;
}