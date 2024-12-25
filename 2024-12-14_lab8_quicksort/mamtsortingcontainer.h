#ifndef MAMTSORTINGCONTAINER_H
#define MAMTSORTINGCONTAINER_H


#include <cmath>
#include <thread>
// #include <iostream>
#include "sortingcontainer.h"

// MAMT - multiarray & multithread
template<class T>
class MAMTSortingContainer : public SortingContainer<T>
{
protected:
    virtual void _quickSort(unsigned int hasThreads, unsigned int start, unsigned int finish)
    {
        // One element array
        if (finish <= 1) return;

        unsigned int i{start};
        unsigned int j{finish - 1};
        T midVal = this->arr[(j + i) / 2];
        do {
            while (this->arr[i] < midVal) ++i;
            while (this->arr[j] > midVal) --j;
            if (i <= j) {
                std::swap(this->arr[i], this->arr[j]);
                ++i;
                --j;
            }
        } while (i <= j);

        // if (j > start) _quickSort(0, start, j + 1);
        // if (i < finish) _quickSort(0, i, finish);
        // return;
        std::thread * threads = new std::thread[2];

        if (j > start)
        {
            if (hasThreads)
            {
                threads[0] = std::thread(&MAMTSortingContainer::_quickSort, this, hasThreads - 1, start, j + 1);
            }
            else
            {
                _quickSort(0, start, j + 1);
            }
        }
        if (i < finish)
        {
            if (hasThreads)
            {
                threads[1] = std::thread(&MAMTSortingContainer::_quickSort, this, hasThreads - 1, i, finish);
            }
            else
            {
                _quickSort(0, i, finish);
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

public:
    MAMTSortingContainer(unsigned int size): SortingContainer<T>(size) {};

    virtual void quickSort() override
    {
        _quickSort(std::floor(std::log2(std::thread::hardware_concurrency())), 0, this->n);
    }
};

#endif // MAMTSORTINGCONTAINER_H
