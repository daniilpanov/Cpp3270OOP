#include <iostream>
#include "configparser.h"
#include "tabulator.h"
#include "currentfunction.h"

using namespace std;

int main()
{
    ConfigParser config;
    config.read(cin);
    cout << "Configuration [start - end - step]: " << config.conf.start << " - " << config.conf.end << " - " << config.conf.step << endl;
    CurrentFunction * const function = new CurrentFunction();
    Tabulator tabulator(config.conf);
    tabulator.addFunctionObject(function);
    tabulator.tabulate(cout);
    delete function;
    return 0;
}
