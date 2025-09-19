#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "array_bounds.hpp"

#include <cstring>
#include <cassert>
#include <iostream>
#include <string>

TEST_CASE("given+ against eachother","[given + against eachother]"){
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

        // Test recursive vs iterative implementations
        assert(lower_bound(a, n, t) == lower_bound_iterative(a, n, t));
        assert(upper_bound(a, n, t) == upper_bound_iterative(a, n, t));

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

TEST_CASE("negative and large values","[negative and large values]"){
    int a[] = {-99999, -99999, -2, -5, -5, 0, 5, 10, 999, 99999, 999999};
    int n = sizeof(a) / sizeof(a[0]);

    // Test cases with various target values
    for (int t : {-300000, -20, -1, 0, 2, 3, 5, 6, 10, 11}) {
        // Test iterative implementations
        assert(lower_bound_iterative(a, n, t) == std_lower_bound(a, n, t));
        assert(upper_bound_iterative(a, n, t) == std_upper_bound(a, n, t));

        // Test recursive implementations
        assert(lower_bound(a, n, t) == std_lower_bound(a, n, t));
        assert(upper_bound(a, n, t) == std_upper_bound(a, n, t));

         // Test recursive vs iterative implementations
        assert(lower_bound(a, n, t) == lower_bound_iterative(a, n, t));
        assert(upper_bound(a, n, t) == upper_bound_iterative(a, n, t));

        // Test frequency calculation
        assert(frequency(a, n, t) == std_frequency(a, n, t));
        assert(frequency_iterative(a, n, t) == std_frequency(a, n, t));

        std::cout << "Target_2 " << t << ": ";
        std::cout << "LB_2=" << lower_bound(a, n, t) << ", ";
        std::cout << "UB_2=" << upper_bound(a, n, t) << ", ";
        std::cout << "Freq_2=" << frequency(a, n, t) << std::endl;
    }

    std::cout << "All tests_2 passed!" << std::endl;
}

TEST_CASE("specific","[specific]"){
    int a[] = {-1, -1, 0, 2, 3, 5, 6, 10, 10, 10, 11, 11};
    int n = sizeof(a) / sizeof(a[0]);
    //size of = array length*4 (int is 4 bytes) 
    //dived by sizeof(a[0]) to divide by 4 to get the actual length

    
        assert(lower_bound_iterative(a, n, -1) == 0);
        assert(lower_bound_iterative(a, n, 2) == 3);
        assert(lower_bound_iterative(a, n, 9) == 7);
        assert(lower_bound_iterative(a, n, 10) == 7);
        assert(lower_bound_iterative(a, n, 20) == 12);

        assert(upper_bound_iterative(a, n, -1) == 2);
        assert(upper_bound_iterative(a, n, 5) == 6);
        assert(upper_bound_iterative(a, n, 10) == 10);
        assert(upper_bound_iterative(a, n, 20) == 12);

        // Test recursive implementations
        assert(lower_bound(a, n, -1) == 0);
        assert(lower_bound(a, n, 2) == 3);
        assert(lower_bound(a, n, 9) == 7);
        assert(lower_bound(a, n, 10) == 7);
        assert(lower_bound(a, n, 20) == 12);

        assert(upper_bound(a, n, -1) == 2);
        assert(upper_bound(a, n, 5) == 6);
        assert(upper_bound(a, n, 10) == 10);
        assert(upper_bound(a, n, 20) == 12);

        // Test frequency calculation
        assert(frequency(a, n, -1) == 2);
        assert(frequency_iterative(a, n, -1) == 2);
        assert(frequency(a, n, 10) == 3);
        assert(frequency_iterative(a, n, 10) == 3);
        assert(frequency(a, n, -10) == 0);
        assert(frequency_iterative(a, n, -10) == 0);
        assert(frequency(a, n, 20) == 0);
        assert(frequency_iterative(a, n, 20) == 0);
        assert(frequency(a, n, 11) == 2);
        assert(frequency_iterative(a, n, 11) == 2);
        assert(frequency(a, n, 5) == 1);
        assert(frequency_iterative(a, n, 5) == 1);

        

    std::cout << "ROUND3!" << std::endl;
}