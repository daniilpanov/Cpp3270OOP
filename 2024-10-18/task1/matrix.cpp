#include "matrix.h"
#include <iostream>

Matrix::Matrix(int w, int h, float * matrix): _w(w), _h(h), _matrix(matrix)
{
}

Matrix::Matrix(Matrix & matrix): _w(matrix._w), _h(matrix._h)
{
}

float Matrix::calcDef()
{
    // TODO: triangle form by the 2 cycles
    for (int i{0}, index{0}; i < _w; i += _h, ++index)
    {
        for (int j{index}; j < _h; ++j)
        {

        }
    }

    return 0.0;
}

Matrix::~Matrix()
{
    delete[] _matrix;
}
