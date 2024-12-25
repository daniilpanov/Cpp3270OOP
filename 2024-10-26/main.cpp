#include <iostream>
#include "polyline.h"

using namespace std;


int main()
{
    int length{1};
    Polyline * lines {new Polyline[length]};
    cout << "ok1" << endl;
    lines[0] = Polyline(length);
    cout << "OK" << endl;
    for (int i{0}; i < length; ++i)
    {
        lines[i] = Polyline(length);
        cout << "OK" << endl;
    }
    cout << "ok2" << endl;
    // lines[0].printLine();
    // delete[] lines;
    return 0;
}
