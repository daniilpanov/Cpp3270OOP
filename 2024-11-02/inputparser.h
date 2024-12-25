#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <QString>
#include <QStringList>

class InputParser
{
public:
    int hsize{0};
    int wsize{0};

    double *kMatrix {nullptr};  // koefficients matrix (WxH)
    char *xMatrix {nullptr};  // variables names
    double *bMatrix {nullptr};  // after '='

    InputParser();
    bool parseString(QString);
    ~InputParser();
private:
    void clearValues();
};

#endif // INPUTPARSER_H
