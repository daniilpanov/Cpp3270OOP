#include "sort.h"
#include <iostream>
#include <utility>

template<>
void randomFill<int>(unsigned int n, int * arr)
{
    for (unsigned int i{0}; i < n; ++i)
    {
        arr[i] = rand() % 10;
    }
}

template<>
void randomFill<double>(unsigned int n, double * arr)
{
    for (unsigned int i{0}; i < n; ++i)
    {
        arr[i] = 1.0*(rand() % 10)/(rand()%10+1);
    }
}

template<>
void randomFill<char>(unsigned int n, char * arr)
{
    int grow = 'z' - 'A';
    for (unsigned int i{0}; i < n; ++i)
    {
        arr[i] = rand() % grow + 'A';
    }
}

template<typename T>
void print(T * arr, unsigned int n)
{
    if(arr != nullptr)
    {
        for (unsigned int i{0}; i < n; i++)
        {
            std::cout << arr[i] << "\t";
        }
    }
    std::cout << "\n";
}
