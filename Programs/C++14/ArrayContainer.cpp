/*
 * ArrayContainer.cpp
 *
 *  Created on: Aug 24, 2019
 *      Author: Prash
 */

/* arr1.cpp */
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

int ArrayContainer_main()
{
    // construction uses aggregate initialization
    std::array<int, 5> i_array1{ {3, 4, 5, 1, 2} };  // double-braces required
    std::array<int, 5> i_array2 = {1, 2, 3, 4, 5};   // except after =
    std::array<std::string, 2> string_array = { {std::string("a"), "b"} };

    std::cout << "Initial i_array1 : ";
    for(auto i: i_array1)
        std::cout << i << ' ';
    // container operations are supported
    std::sort(i_array1.begin(), i_array1.end());

    std::cout << "\nsored i_array1 : ";
    for(auto i: i_array1)
        std::cout << i << ' ';

    std::cout << "\nInitial i_array2 : ";
    for(auto i: i_array2)
        std::cout << i << ' ';

    std::cout << "\nreversed i_array2 : ";
    std::reverse_copy(i_array2.begin(), i_array2.end(),
                      std::ostream_iterator<int>(std::cout, " "));

    // ranged for loop is supported
    std::cout << "\nstring_array : ";
    for(auto& s: string_array)
        std::cout << s << ' ';

    return 0;
}


