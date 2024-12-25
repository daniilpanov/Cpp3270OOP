#ifndef SORTINGCONTAINER_H
#define SORTINGCONTAINER_H

#include <cstdlib>
// #include <iostream>

template<class T>
class SortingContainer
{
protected:
    unsigned int n{0};
    T * arr{nullptr};

    virtual void _quickSort(unsigned int start, unsigned int finish)
    {
        unsigned int i{start};
        unsigned int j{finish - 1};
        T midVal = arr[(j + i) / 2];
        do {

            while (arr[i] < midVal) ++i;
            while (arr[j] > midVal) --j;
            if (i <= j) {
                T tmp{arr[i]};
                arr[i] = arr[j];
                arr[j] = tmp;
                ++i;
                --j;
            }
        } while (i <= j);
        if (j > start) _quickSort(start, j + 1);
        if (i < finish) _quickSort(i, finish);
    }
public:
    SortingContainer(unsigned int size): n(size) {};

    virtual ~SortingContainer()
    {
        if (arr != nullptr)
        {
            delete[] arr;
            arr = nullptr;
        }
    }

    void quickSort()
    {
        _quickSort(0, n);
    }

    void randomFill();

    void print() const
    {
        if(arr != nullptr)
        {
            for (unsigned int i{0}; i < n; i++)
            {
                //std::cout << arr[i] << "\t";
            }
        }
        //std::cout << "\n";
    }
};

#endif // SORTINGCONTAINER_H
