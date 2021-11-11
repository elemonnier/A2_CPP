#include "exercise2.h"

/// Point's methods:

double Point::distance(Point P) {
    return sqrt((x - P.x) * (x - P.x) + (y - P.y) * (y - P.y));
}

Point Point::milieu(Point P) {
    auto milieu = new Point;
    milieu->x = ((P.x + x)/2);
    milieu->y = ((P.y + y)/2);
    return *milieu;
}

void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

double Point::getX() {
    return this->x;
}

double Point::getY() {
    return this->y;
}

void Point::saisir() {
    double tmpX, tmpY;
    cout << "Saisissez les coordonnées : \nAbscisse : ";
    cin >> tmpX;
    setX(tmpX);
    cout << "Ordonnée : ";
    cin >> tmpY;
    setY(tmpY);
}

void Point::afficher() {
    cout << "Les coordonnées sont : (" << getX() << " ; " << getY() << ")\n";
}


/// Point1's methods:

double Point1::distanceDyn(Point1 P) {
    return sqrt((x - P.x) * (x - P.x) + (y - P.y) * (y - P.y));
}

Point1 Point1::milieuDyn(Point1 P) {
    auto milieu = new Point1;
    milieu->x = ((P.x + x)/2);
    milieu->y = ((P.y + y)/2);
    return *milieu;
}

void Point1::setXdyn(double x) {
    this->x = x;
}

void Point1::setYdyn(double y) {
    this->y = y;
}

double Point1::getXdyn() {
    return this->x;
}

double Point1::getYdyn() {
    return this->y;
}

void Point1::saisirDyn() {
    double tmpX, tmpY;
    cout << "Saisissez les coordonnées : \nAbscisse : ";
    cin >> tmpX;
    setXdyn(tmpX);
    cout << "Ordonnée : ";
    cin >> tmpY;
    setYdyn(tmpY);
}

void Point1::afficherDyn() {
    cout << "(" << getXdyn() << " , " << getYdyn() << ") ";
}