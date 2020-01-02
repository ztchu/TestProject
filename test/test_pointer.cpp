#include "test_pointer.h"

#include <memory>
#include<stdint.h>

namespace test_pointer {
    void TestDeleteNullptr() {
        uint8_t *ptr = nullptr;
        delete ptr;
    }

    class Base {

    };

    class Derived : public Base {

    };
    void TestSmartPointer() {
        std::unique_ptr<Base> b_ptr(new Derived);
    }
}