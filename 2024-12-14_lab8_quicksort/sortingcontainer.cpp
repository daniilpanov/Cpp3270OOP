#include "sortingcontainer.h"

template<>
void SortingContainer<int>::randomFill()
{
    if (arr != nullptr) delete[] arr;
    arr = new int[n];
    for (unsigned int i{0}; i < n; ++i)
    {
        arr[i] = rand() % 10;
    }
}

template<>
void SortingContainer<double>::randomFill()
{
    if (arr != nullptr) delete[] arr;
    arr = new double[n];
    for (unsigned int i{0}; i < n; ++i)
    {
        arr[i] = 1.0*(rand() % 10)/(rand()%10+1);
    }
}

template<>
void SortingContainer<char>::randomFill()
{
    if (arr != nullptr) delete[] arr;
    arr = new char[n];
    int grow = 'z' - 'A';
    for (unsigned int i{0}; i < n; ++i)
    {
        arr[i] = rand() % grow + 'A';
    }
}

