#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>


class Matrix
{
private:
    int _w{0};
    int _h{0};
    const float * _matrix;
public:
    Matrix() = default;
    Matrix(Matrix&);
    Matrix(const int, const int, float *);
    float calcDef();
    void toTriangleForm();
    ~Matrix();
};

#endif // MATRIX_H
