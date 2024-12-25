#include <iostream>
#include "tabulator.h"

Tabulator::Tabulator(const TabulateConfig & conf): cf(conf)
{
    length = (cf.end - cf.start) / cf.step;
}

void Tabulator::addFunctionObject(const AbstractFunction * func)
{
    af = func;
    length = (cf.end - cf.start) / cf.step;
}

void Tabulator::tabulate(double * outX, double * outY)
{
    std::cout << "Tabulation started!" << std::endl;
    double x{cf.start}, y{0.0};
    for (int k {0}; k <= length; ++k, x = cf.start + k * cf.step)
    {
        y = (*af)(x);
        outX[k] = x;
        outY[k] = y;
    }
    std::cout << "Tabulation finished!" << std::endl;
}
