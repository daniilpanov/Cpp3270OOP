#include "kramersystem.h"

KramerSystem::KramerSystem(int size, double* kMatrix, double* bMatrix) : _bMatrix(bMatrix)
{
    _kMatrix = Matrix(size);
    for (int i {0}; i < size; ++i)
    {
        for (int j {0}; j < size; ++j)
        {
            _kMatrix(i, j) = kMatrix[i * size + j];
        }
    }
    delete[] kMatrix;
}

KramerSystem::~KramerSystem()
{
    delete[] _bMatrix;
}

std::string KramerSystem::repr()
{
    return _kMatrix.repr();
}


double* KramerSystem::solve() {
    double det = _kMatrix.determinant();

    // For simplify :) I know that is maybe not correct, but it works fine and very fast
    if (det == 0)
        throw false;

    double* res = new double[_kMatrix.getLength()];

    for (int i {0}; i < _kMatrix.getLength(); ++i)
    {
        Matrix tmpMatrix {_kMatrix};
        tmpMatrix.replaceCol(i, _bMatrix);
        res[i] = tmpMatrix.determinant() / det;
    }
    return res;
}
