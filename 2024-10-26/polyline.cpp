#include <iostream>
#include <algorithm>
#include <atomic>
#include "polyline.h"


Polyline::Polyline(int len): _length(len)
{
    _points = new Point[_length];
}

Polyline::Polyline(int length, Point *points): _length(length), _points(points)
{
}

void Polyline::addPoint(Point &&point)
{
    Point * points = _points;
    std::atomic<Point *> new_points = new Point[_length + 1];
    std::atomic<int> idx = 0;
    std::for_each(&points[0], &points[_length - 1], [&](Point& pnt) {
        new_points[idx++] = pnt;
    });
    new_points[idx] = point;
    _points = new_points;
    delete[] points;
}

void Polyline::printLine()
{
    std::cout << "OK!" << _points[1].x << std::endl;
}

Polyline::~Polyline()
{
    std::cout << "DELETE!" << std::endl;
    delete[] _points;
}


