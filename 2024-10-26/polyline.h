#ifndef POLYLINE_H
#define POLYLINE_H

#include "point.h"


class Polyline
{
private:
    int _length{0};
    Point * _points;
public:
    Polyline() = default;
    Polyline(int);
    Polyline(int, Point *);
    void addPoint(Point&&);
    void printLine();
    Point& getPoint(int);
    int countPoints();
    ~Polyline();
};

#endif // POLYLINE_H
