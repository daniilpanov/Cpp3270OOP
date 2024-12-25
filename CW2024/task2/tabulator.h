#ifndef TABULATOR_H
#define TABULATOR_H

#include <iostream>
#include "config.h"
#include "abstractfunction.h"

class Tabulator
{
private:
    const TabulateConfig & cf;
    const AbstractFunction * af {nullptr};
public:
    Tabulator(const TabulateConfig &);
    void addFunctionObject(const AbstractFunction *);
    void tabulate(std::ostream &);
};

#endif // TABULATOR_H
