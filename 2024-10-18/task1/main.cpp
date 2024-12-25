#include <iostream>
#include <memory>
#include "matrix.h"

using namespace std;

float * generateMatrix(int w, int h)
{
    float * matrix {new float [h * w]};

    for (int i{0}; i < h * w; ++i)
    {
        matrix[i] = (float)(rand() % 10);
    }

    return matrix;
}

int main()
{
    const int w{rand() % 5 + 1}, h{rand() % 5 + 1};
    Matrix m(w, h, generateMatrix(w, h));
    return 0;
}
