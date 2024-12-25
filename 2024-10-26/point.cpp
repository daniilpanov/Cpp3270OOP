#include <iostream>
#include <algorithm>
#include "point.h"

Point::Point(float cx, float cy, float cz): x(cx), y(cy), z(cz)
{
}

auto moveLambda = [](Point &pnt1, Point &pnt) {
    pnt1.x = pnt.x;
    pnt1.y = pnt.y;
    pnt1.z = pnt.z;
};

Point::Point(Point & pnt)
{
    moveLambda(*this, pnt);
}

Point::Point(Point && pnt)
{
    moveLambda(*this, pnt);
}

void Point::operator =(Point & pnt)
{
    moveLambda(*this, pnt);
}

Point::~Point()
{
    std::cout << "DEL" << std::endl;
}

void Point::operator =(Point && pnt)
{
    moveLambda(*this, pnt);
}


