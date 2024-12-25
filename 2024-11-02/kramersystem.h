#ifndef KRAMERSYSTEM_H
#define KRAMERSYSTEM_H

#include "matrix.h"

class KramerSystem
{
private:
    double* _bMatrix;
    Matrix _kMatrix {};

public:
    KramerSystem(int, double*, double*);
    ~KramerSystem();
    double* solve();
    std::string repr();
};

#endif // KRAMERSYSTEM_H
