# owi_optional - standard c++ std::optional with iterators

## Motivation

Enable usage of `optional` in contexts where containers can be used (in range-based for loop, in standard algorithms, generic template functions that receive iterators or range as arguments).

### Basic example

```C++
#include <iostream>
#include <numeric>

#include "owi/optional.hpp"

int main(void)
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
```

Output:
```text
====   RANGE-BASED FOR LOOP  ====
42

====   RANGE-BASED FOR LOOP for empty optional  ====

====   Standard algorigms with optional  ====
Sum of elements: 42
```

## License

<img align="right" src="http://opensource.org/trademarks/opensource/OSI-Approved-License-100x137.png">

The class is licensed under the [MIT License](http://opensource.org/licenses/MIT):

Copyright &copy; 2021 Seleznev Anton

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.





