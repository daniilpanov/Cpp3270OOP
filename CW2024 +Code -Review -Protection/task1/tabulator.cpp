#include "tabulator.h"

void tabulate(double (*func)(double), const TabulateConfig & conf, std::ostream & output)
{
    std::cout << "Tabulation started!" << std::endl;
    double x{conf.start}, y{0.0};
    for (int k {0}; k <= (conf.end - conf.start) / conf.step; ++k, x = conf.start + k * conf.step)
    {
        y = func(x);
        // NaN checking
        if (y != y)
        {
            output << "X: " << x << ", Y: " << "Unreachable value" << std::endl;
        }
        else
        {
            output << "X: " << x << ", Y: " << y << std::endl;
        }
    }
    std::cout << "Tabulation finished!" << std::endl;
}
