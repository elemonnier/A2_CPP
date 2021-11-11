//
// Created by upupu on 05/12/2019.
//

#ifndef TP6_POINT_H
#define TP6_POINT_H

#include <cmath>

class Point {
private:
    float x;
    float y;
public:
    Point(float, float);

    Point(Point const &P);

    float getX();

    float getY();

    void setX(float);

    void setY(float);

    virtual void moveTo(float, float);
};


#endif //TP6_POINT_H