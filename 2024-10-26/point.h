#ifndef POINT_H
#define POINT_H


class Point
{
public:
    float x{0}, y{0}, z{0};
    Point() = default;
    Point(float, float, float);
    Point(Point&);
    Point(Point&&);
    void operator =(Point&);
    void operator =(Point&&);
    ~Point();
};

#endif // POINT_H
