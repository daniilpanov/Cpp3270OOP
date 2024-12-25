#include "matrix.h"
#include "math.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

Matrix::Matrix(int n) : size(n)
{
    matr = new double[size];

    for (int i {0}; i < size; ++i)
    {
        for (int j {0}; j < size; ++j)
        {
            matr[i * size + j] = 0;
        }
    }
}

Matrix::Matrix(Matrix& other) : size(other.size)
{
    matr = new double[size];

    for (int i {0}; i < size; ++i)
    {
        for (int j {0}; j < size; ++j)
        {
            matr[i * size + j] = other(j, i);
        }
    }
}

double& Matrix::operator()(int x, int y)
{
    return matr[y * size + x];
}

void Matrix::operator=(Matrix &&other)
{
    size = other.size;
    matr = new double[size];
}

void Matrix::replaceCol(int n, double* col)
{
    for (int y {0}; y < size; ++y)
    {
        matr[y * size + n] = col[y];
    }
}

double Matrix::determinant()
{
    Matrix tmpMatr {*this};
    double res {1};

    for (int i1 {0}; i1 < size; ++i1)
    {
        for (int i2 {i1 + 1}; i2 < size; ++i2)
        {
            if (tmpMatr(i2, i1) == 0 || tmpMatr(i1, i1) == 0) {
                return 0;
            }
            double k {tmpMatr(i2, i1) / tmpMatr(i1, i1)};
            for (int j {0}; j < size; ++j)
            {
                tmpMatr(i2, j) = tmpMatr(i2, j) - tmpMatr(i1, j) * k;
            }
        }
    }

    for (int i {0}; i < size; ++i)
    {
        res *= tmpMatr(i, i);
    }

    return res;
}

std::string Matrix::repr()
{
    std::ostringstream oss;
    for (int i {0}; i < size; ++i)
    {
        for (int j {0}; j < size; ++j)
        {
            oss << std::setw(8) << std::setprecision(4) << matr[i * size + j] << ' ';
        }
        oss << std::endl;
    }
    return oss.str();
}

int Matrix::getLength()
{
    return size;
}

Matrix::~Matrix()
{
    // delete[] matr;
}
