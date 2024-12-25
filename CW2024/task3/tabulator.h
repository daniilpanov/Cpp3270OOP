#ifndef TABULATOR_H
#define TABULATOR_H

#include "config.h"
#include "abstractfunction.h"

class Tabulator
{
private:
    const TabulateConfig & cf;
    const AbstractFunction * af {nullptr};
public:
    int length{0};
    Tabulator(const TabulateConfig &);
    void addFunctionObject(const AbstractFunction *);
    void tabulate(double *, double *);
};

#endif // TABULATOR_H
