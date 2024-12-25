#ifndef MAMTSORTINGCONTAINER_H
#define MAMTSORTINGCONTAINER_H


#include <cmath>
#include <mutex>
#include <thread>
#include "sortingcontainer.h"

// MAMT - multiarray & multithread
template<class T>
class MAMTSortingContainer : public SortingContainer<T>
{
protected:
    T * arr1{nullptr};
    T * arr2{nullptr};
    std::mutex arrayMtx1;
    std::mutex arrayMtx2;

    virtual void _quickSortPart(unsigned int start, unsigned int finish, unsigned int hasThreads, T * arr, std::mutex &mtx)
    {
        // One element array
        if (finish - start <= 1) return;

        unsigned int i{start};
        unsigned int j{finish - 1};
        T midVal = arr[(j + i) / 2];
        do {
            while (arr[i] < midVal) ++i;
            while (arr[j] > midVal) --j;
            if (i <= j) {
                std::lock_guard<std::mutex> lock(mtx);
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
                threads[0] = std::thread(&MAMTSortingContainer::_quickSortPart, this, start, j + 1, hasThreads - 1, arr, std::ref(mtx));
            }
            else
            {
                _quickSortPart(start, j + 1, 0, arr, std::ref(mtx));
            }
        }
        if (i < finish)
        {
            if (hasThreads)
            {
                threads[1] = std::thread(&MAMTSortingContainer::_quickSortPart, this, i, finish, hasThreads - 1, arr, std::ref(mtx));
            }
            else
            {
                _quickSortPart(i, finish, 0, arr, std::ref(mtx));
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
        unsigned int half{(finish - start) / 2 + start};
        arr1 = new T[half];
        arr2 = new T[finish - start - half];
        for (unsigned int i{start}; i < finish; ++i)
        {
            if (i < half) arr1[i] = this->arr[i];
            else arr2[i] = this->arr[i];
        }

        std::thread th1(&MAMTSortingContainer<T>::_quickSortPart, this, start, half, std::floor(std::log2(std::thread::hardware_concurrency())) - 1, arr1, std::ref(arrayMtx1));
        std::thread th2(&MAMTSortingContainer<T>::_quickSortPart, this, half, finish, std::floor(std::log2(std::thread::hardware_concurrency())) - 1, arr2, std::ref(arrayMtx2));

        th1.join();
        th2.join();

        delete[] arr1;
        delete[] arr2;
    }

public:
    MAMTSortingContainer(unsigned int size): SortingContainer<T>(size) {};
};


#endif // MAMTSORTINGCONTAINER_H
