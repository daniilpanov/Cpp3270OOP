#include "reader.h"


TabulateConfig * readConfig(std::istream & input)
{
    TabulateConfig * conf = new TabulateConfig;
    input >> conf->start >> conf->end >> conf->step;

    return conf;
}
