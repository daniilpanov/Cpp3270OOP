#include <iostream>
#include <chrono>
#include "mamtsortingcontainer.h"
#include "multithreadsortingcontainer.h"

using namespace std::chrono;

milliseconds functionTime(void (*func)())
{
    auto begin{steady_clock::now()};
    func();
    auto end{steady_clock::now()};
    auto elapsed_ms{duration_cast<milliseconds>(end - begin)};
    return elapsed_ms;
}

int main()
{
    milliseconds result{functionTime(([]()->void {
        SortingContainer<int> M(100000);
        M.randomFill();
        M.print();
        M.quickSort();
        M.print();
    }))};
    std::cout << "Time elapsed without threads: " << result.count() << " ms" << std::endl;
    result = functionTime(([]()->void {
        MultiThreadSortingContainer<int> M(1000000);
        M.randomFill();
        M.print();
        M.quickSort();
        M.print();
    }));
    std::cout << "Time elapsed within threads: " << result.count() << " ms" << std::endl;
    result = functionTime(([]()->void {
        MAMTSortingContainer<int> M(10000000);
        M.randomFill();
        M.print();
        M.quickSort();
        M.print();
    }));
    std::cout << "Time elapsed within threads and splitting an array: " << result.count() << " ms" << std::endl;
    return 0;
}
