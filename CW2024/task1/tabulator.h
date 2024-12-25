#ifndef TABULATOR_H
#define TABULATOR_H
#include <iostream>
#include "config.h"

void tabulate(double (*)(double), const TabulateConfig &, std::ostream &);

#endif // TABULATOR_H
