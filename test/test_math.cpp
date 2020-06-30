#include "test_math.h"

#include <cmath>
#include <iostream>


namespace test_math {
    void TestCeil() {
        float input = 0.001;
        std::cout << std::ceil(input) << std::endl;
        std::cout << std::floor(input) << std::endl;
    }
}
