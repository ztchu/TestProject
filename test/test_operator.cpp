#include "test_operator.h"

#include <iostream>

namespace test_operator {
    void TestXor() {
        int a = 1233, b = 2355, c = 3235;
        int ret = a ^ b ^ c;
        std::cout << "ret: " << ret << std::endl;

        auto ret_b = ret ^ a ^ c;
        std::cout << "ret xor a xor c: " << ret_b << std::endl;
        auto ret_a = ret ^ b ^ c;
        std::cout << "ret xor b xor c: " << ret_a << std::endl;
    }
}