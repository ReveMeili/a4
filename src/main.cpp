//src/main.cpp

#include "array_bounds.hpp"
#include <cassert>
#include <iostream>

void test_binary_search() {
    int a[] = {2, 5, 5, 5, 10};
    int n = sizeof(a) / sizeof(a[0]);

    // Test cases with various target values
    for (int t : {-1, 0, 2, 3, 5, 6, 10, 11}) {
        // Test iterative implementations
        assert(lower_bound_iterative(a, n, t) == std_lower_bound(a, n, t));
        assert(upper_bound_iterative(a, n, t) == std_upper_bound(a, n, t));

        // Test recursive implementations
        assert(lower_bound(a, n, t) == std_lower_bound(a, n, t));
        assert(upper_bound(a, n, t) == std_upper_bound(a, n, t));

        // Test frequency calculation
        assert(frequency(a, n, t) == std_frequency(a, n, t));
        assert(frequency_iterative(a, n, t) == std_frequency(a, n, t));

        std::cout << "Target " << t << ": ";
        std::cout << "LB=" << lower_bound(a, n, t) << ", ";
        std::cout << "UB=" << upper_bound(a, n, t) << ", ";
        std::cout << "Freq=" << frequency(a, n, t) << std::endl;
    }

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    test_binary_search();
    return 0;
}