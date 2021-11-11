//
// Created by upupu on 05/12/2019.
//

#ifndef TP6_POINT_H
#define TP6_POINT_H


class Point {
private:
    double x;
    double y;
public:
    Point(double, double);

    Point(Point const &P);

    double getX();

    double getY();

    void setX(double);

    void setY(double);
};


#endif //TP6_POINT_H