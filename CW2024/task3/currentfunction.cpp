#include <cmath>
#include "currentfunction.h"

CurrentFunction::CurrentFunction() {}

double CurrentFunction::operator ()(double x) const
{
    return sin(x) * cos(x) * exp(x);
}
