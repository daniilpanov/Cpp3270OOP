#include <iostream>
#include <chrono>
#include <functional>
#include "sort.h"

using namespace std::chrono;

milliseconds functionTime(std::function<void()> func)
{
    auto begin{steady_clock::now()};
    func();
    auto end{steady_clock::now()};
    auto elapsed_ms{duration_cast<milliseconds>(end - begin)};
    return elapsed_ms;
}

int main()
{
    unsigned int n{10000000};
    int * arr = new int[n];
    randomFill(n, arr);
    milliseconds result{functionTime(([n, arr]()->void {
        quickSort(arr, 0, n);
    }))};
    std::cout << "Time elapsed without threads: " << result.count() << " ms" << std::endl;
    result = functionTime(([n, arr]()->void {
        quickSortParallel(arr, 0, n);
    }));
    std::cout << "Time elapsed within threads: " << result.count() << " ms" << std::endl;
    return 0;
}
