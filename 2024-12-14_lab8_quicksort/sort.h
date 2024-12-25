#ifndef SORT_H
#define SORT_H

#include <cstdlib>
#include <cmath>
#include <thread>

template<typename T>
void randomFill(unsigned int, T *);

template<typename T>
void quickSort(T *, unsigned int, unsigned int);

template<typename T>
void print(T *, unsigned int);

// Couldn't initialize in the CPP file :(
template<typename T>
void quickSort(T * arr, unsigned int start, unsigned int finish)
{
    // One element array
    if (finish <= 1) return;

    unsigned int i{start};
    unsigned int j{finish - 1};
    T midVal = arr[(j + i) / 2];
    do {
        while (arr[i] < midVal) ++i;
        while (arr[j] > midVal) --j;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    } while (i <= j);
    if (j > start) quickSort(arr, start, j + 1);
    if (i < finish) quickSort(arr, i, finish);
}

template<typename T>
void quickSortParallel(T * arr, unsigned int start, unsigned int finish, unsigned int hasThreads = std::floor(std::log2(std::thread::hardware_concurrency())))
{
    // One element array
    if (finish <= 1) return;

    unsigned int i{start};
    unsigned int j{finish - 1};
    T midVal = arr[(j + i) / 2];
    do {
        while (arr[i] < midVal) ++i;
        while (arr[j] > midVal) --j;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    } while (i <= j);

    std::thread * threads = new std::thread[2];

    if (j > start)
    {
        if (hasThreads)
        {
            threads[0] = std::thread([arr, start, j, hasThreads](){quickSortParallel(arr, start, j + 1, hasThreads - 1);});
        }
        else
        {
            quickSortParallel(arr, start, j + 1, 0);
        }
    }
    if (i < finish)
    {
        if (hasThreads)
        {
            threads[1] = std::thread([arr, i, finish, hasThreads](){quickSortParallel(arr, i, finish, hasThreads - 1);});
        }
        else
        {
            quickSortParallel(arr, i, finish, 0);
        }
    }
    for (unsigned int i{0}; i < 2; ++i)
    {
        if (threads[i].joinable())
        {
            threads[i].join();
        }
    }
    delete[] threads;
}

#endif // SORT_H
