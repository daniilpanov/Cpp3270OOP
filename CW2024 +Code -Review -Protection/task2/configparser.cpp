#include "configparser.h"

ConfigParser::ConfigParser() {}

void ConfigParser::read(std::istream & input)
{
    input >> conf.start >> conf.end >> conf.step;
}
