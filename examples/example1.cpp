#include <iostream>
#include "owi/optional.hpp"

int main()
{
    static_assert(sizeof(std::optional<char>) == sizeof(owi::optional<char>));
    static_assert(sizeof(std::optional<int>) == sizeof(owi::optional<int>));
    static_assert(sizeof(std::optional<long>) == sizeof(owi::optional<long>));

    owi::optional<int> n = owi::nullopt;

    owi::optional<int> oi{3};
    std::cout << oi.value_or(42) << std::endl;

    auto moi = owi::make_optional<int>(33);
    std::cout << moi.value() << std::endl;

    using oi_it = owi::optional<int>::iterator;
    int k = 3;
    oi_it it{&k};
    oi_it it2{it};
    oi_it it3{std::move(it)};

    std::cout << "== owi::optional<int>{666} ==" << std::endl;
    for (const auto & i : owi::optional<int>{666}) {
        std::cout << i << std::endl;
    }

    std::cout << "== owi::optional<int>{owi::nullopt} ==" << std::endl;
    for (const auto & i : owi::optional<int>{owi::nullopt}) {
        std::cout << i << std::endl;
    }

    {
        owi::optional<int> oi3{3};
        owi::optional<int> oi3_{3};
        // todo
        //std::cout << (oi3 == oi3_) << std::endl;
    }
}