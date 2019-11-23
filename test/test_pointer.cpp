#include "test_pointer.h"

#include<stdint.h>

namespace test_pointer {
    void TestDeleteNullptr() {
        uint8_t *ptr = nullptr;
        delete ptr;
    }
}