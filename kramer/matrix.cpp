#include "Matrix.h"
#include "math.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <utility>

Matrix::Matrix(int n) : size(n) {
    matr = new double* [size];
    for (int i = 0; i < size; i++) {
        matr[i] = new double[size];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matr[i][j] = 0;
        }
    }

}

Matrix::Matrix(Matrix& other) : size(other.size) {
    matr = new double* [size];
    for (int i = 0; i < size; i++) {
        matr[i] = new double[size];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matr[i][j] = other(j, i);
        }
    }
}

double& Matrix::operator()(int x, int y) {
    return matr[y][x];
}

void Matrix::replaceCol(int n, double* col) {
    for (int y = 0; y < size; y++)
    {
        matr[y][n] = col[y];
    }
}

double Matrix::determinant() {
    Matrix tmpMatr{ *this };
    double res = 1;

    for (int i1 = 0; i1 < size; i1++) {
        for (int i2 = i1 + 1; i2 < size; i2++) {
            double k = tmpMatr(i2, i1) / tmpMatr(i1, i1);
            for (int j = 0; j < size; j++)
            {
                tmpMatr(i2, j)= tmpMatr(i2, j)- tmpMatr(i1, j)* k;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        res *= tmpMatr(i, i);
    }

    return res;
}

std::string Matrix::repr() {
    std::ostringstream oss;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            oss << std::setw(8) << std::setprecision(4) << matr[i][j] << " ";
        }
        oss << "\n";
    }
    return oss.str();

}

int Matrix::getLength() {
    return size;
}

Matrix::~Matrix() {
    for (int i = 0; i < size; i++)
    {
        delete[] matr[i];
    }
    delete[] matr;
}