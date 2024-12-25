#include <iostream>
#include <fstream>
#include "reader.h"
#include "tabulator.h"
#include "function.h"

using namespace std;

int main()
{
    std::ifstream inputReader("./input.txt");
    if (!inputReader || !inputReader.is_open()) {
        cerr << "Error: " << "Can't open the input file!" << endl;
        return 1;
    }
    const TabulateConfig conf {*readConfig(inputReader)};
    inputReader.close();

    cout << "Configuration [start - end - step]: " << conf.start << " - " << conf.end << " - " << conf.step << endl;
    ofstream outputFile("./output.txt");
    if (!outputFile || !outputFile.is_open()) {
        cerr << "Error: " << "Can't open the output file!" << endl;
        return 1;
    }
    tabulate(function, conf, outputFile);
    outputFile.flush();
    outputFile.close();

    return 0;
}
