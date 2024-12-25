#ifndef CURRENTFUNCTION_H
#define CURRENTFUNCTION_H

#include "abstractfunction.h"

class CurrentFunction : public AbstractFunction
{
public:
    CurrentFunction();
    virtual double operator ()(double) const override;
};

#endif // CURRENTFUNCTION_H
