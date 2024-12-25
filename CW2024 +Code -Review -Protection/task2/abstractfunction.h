#ifndef ABSTRACTFUNCTION_H
#define ABSTRACTFUNCTION_H

class AbstractFunction
{
public:
    AbstractFunction() = default;
    AbstractFunction(AbstractFunction &) = default;
    AbstractFunction(AbstractFunction &&) = default;
    virtual ~AbstractFunction() = default;
    virtual double operator()(double) const = 0;
};

#endif // ABSTRACTFUNCTION_H
