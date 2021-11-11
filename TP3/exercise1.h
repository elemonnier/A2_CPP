#ifndef TP3_EXERCISE1_H
#define TP3_EXERCISE1_H

class Point {
private:
    double x, y;
public:
    double distance(Point P);
    Point midpoint(Point P);
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
    void enter();
    void display();
    Point();
    Point(double);
    Point(double, double);
};

#endif