#ifndef MULTITHREADSORTINGCONTAINER_H
#define MULTITHREADSORTINGCONTAINER_H

#include <cmath>
#include <mutex>
#include <thread>
#include "sortingcontainer.h"

template<class T>
class MultiThreadSortingContainer : public SortingContainer<T>
{
protected:
    std::mutex arrayMtx;

    virtual void _quickSortPart(unsigned int start, unsigned int finish, unsigned int hasThreads = std::floor(std::log2(std::thread::hardware_concurrency())))
    {
        // One element array
        if (finish - start <= 1) return;

        unsigned int i{start};
        unsigned int j{finish - 1};
        T midVal = this->arr[(j + i) / 2];
        do {
            while (this->arr[i] < midVal) ++i;
            while (this->arr[j] > midVal) --j;
            if (i <= j) {
                std::lock_guard<std::mutex> lock(arrayMtx);
                std::swap(this->arr[i], this->arr[j]);
                ++i;
                --j;
            }
        } while (i <= j);

        std::thread * threads = new std::thread[2];

        if (j > start)
        {
            if (hasThreads)
            {
                threads[0] = std::thread(&MultiThreadSortingContainer::_quickSortPart, this, start, j + 1, hasThreads - 1);
            }
            else
            {
                _quickSortPart(start, j + 1, 0);
            }
        }
        if (i < finish)
        {
            if (hasThreads)
            {
                threads[1] = std::thread(&MultiThreadSortingContainer::_quickSortPart, this, i, finish, hasThreads - 1);
            }
            else
            {
                _quickSortPart(i, finish, 0);
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

    virtual void _quickSort(unsigned int start, unsigned int finish) override
    {
        _quickSortPart(start, finish);
    }

public:
    MultiThreadSortingContainer(unsigned int size): SortingContainer<T>(size) {};
};

#endif // MULTITHREADSORTINGCONTAINER_H
