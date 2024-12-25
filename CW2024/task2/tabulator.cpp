#include <cmath>
#include "tabulator.h"

Tabulator::Tabulator(const TabulateConfig & conf): cf(conf)
{
}

void Tabulator::addFunctionObject(const AbstractFunction * func)
{
    af = func;
}

void Tabulator::tabulate(std::ostream & out)
{
    std::cout << "Tabulation started!" << std::endl;
    double x {cf.start};
    double y {0.0};

    while (x <= cf.end)
    {
        y = (*af)(x);
        if (std::isnan(y))
        {
            out << "X: " << x << ", Y: " << "Unreachable value" << std::endl;
        }
        else
        {
            out << "X: " << x << ", Y: " << y << std::endl;
        }
        x += cf.step;
    }
    std::cout << "Tabulation finished!" << std::endl;
}
