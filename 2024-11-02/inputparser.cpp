#include "inputparser.h"
#include <QRegExp>

InputParser::InputParser()
{
}

bool InputParser::parseString(QString str)
{
    clearValues();
    const QStringList rows {str.split('\n', Qt::SplitBehaviorFlags::SkipEmptyParts)};
    const int h {rows.size()};
    kMatrix = new double[h*h];
    bMatrix = new double[h];
    xMatrix = new char[h];
    QString row;
    bool xInitialized {false};
    QRegExp valuesParser("([\\+\\-]?) *([\\d.]+) *\\* *([a-z])");

    for (int i{0}; i < h; ++i)
    {
        row = rows[i].trimmed();
        const QStringList splitByEq {row.split('=')};
        if (splitByEq.size() != 2)
        {
            return false;
        }
        // splitByEq[0] - left part, splitByEq[1] - right part
        // right part
        bMatrix[i] = splitByEq[1].trimmed().toDouble();

        // left part
        int pos {0};
        int j {0};

        while ((pos = valuesParser.indexIn(splitByEq[0], pos)) != -1) {
            pos += valuesParser.matchedLength();

            // Assert: one line is bigger than rows number
            if (j >= h)
            {
                return false;
            }

            QString sign {valuesParser.cap(1).trimmed()};
            QString kVal {valuesParser.cap(2).trimmed()};
            QString xVal {valuesParser.cap(3).trimmed()};

            char kk {-1};
            if (!sign.length() || sign == "+") {
                kk = 1;
            }

            kMatrix[i * h + j] = kk * kVal.toDouble();
            if (!xInitialized)
            {
                xMatrix[j] = xVal[0].toLatin1();
            }
            ++j;
        }
        if (j != h)
            return false;
        xInitialized = true;
    }

    hsize = wsize = h;

    return true;
}

InputParser::~InputParser()
{
    clearValues();
}

void InputParser::clearValues()
{
    hsize = 0;
    wsize = 0;
//    if (kMatrix != nullptr)
//    {
//        delete[] kMatrix;
//        kMatrix = nullptr;
//    }
//    if (xMatrix != nullptr)
//    {
//        delete[] xMatrix;
//        xMatrix = nullptr;
//    }
//    if (bMatrix != nullptr)
//    {
//        delete[] bMatrix;
//        bMatrix = nullptr;
//    }
}


