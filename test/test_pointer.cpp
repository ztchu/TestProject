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

    struct Foo {
        static const auto var2_ = 0;
        // auto var1_ = 0;    auto can't define non static member variable.
    };

    void TestAuto() {
        int arr[10] = { 0 };
        auto aa = arr;
        // auto rr[10] = arr; auto can't define array.
    }
}