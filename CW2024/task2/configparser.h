#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include "config.h"
#include <iostream>

class ConfigParser
{
public:
    TabulateConfig conf;
    ConfigParser();
    void read(std::istream &);
};

#endif // CONFIGPARSER_H
