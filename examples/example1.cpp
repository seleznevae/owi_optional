#include <iostream>
#include <numeric>
#include "owi/optional.hpp"

int main()
{
    owi::optional<int> opt{42};
    owi::optional<int> empty;

    std::cout << "====   RANGE-BASED FOR LOOP  ====\n";
    for (int i : opt)
        std::cout << i << std::endl;

    std::cout << "\n====   RANGE-BASED FOR LOOP for empty optional  ====\n";
    for (int i : empty)
        std::cout << i << std::endl;

    std::cout << "\n====   Standard algorigms with optional  ====\n";
    std::cout << "Sum of elements: " << std::accumulate(opt.cbegin(), opt.cend(), 0) << std::endl;

}