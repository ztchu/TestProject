#include "test_typetraits.h"

#include <iostream>
#include <type_traits>

namespace test_typetraits {
    void TestTraitsConst() {
        std::cout << "is const: " << std::endl;
        std::cout << "int: " << std::is_const<int>::value << std::endl;
        std::cout << "const int: " << std::is_const<const int>::value << std::endl;
        std::cout << "const int&: " << std::is_const<const int&>::value << std::endl;
        std::cout << "const int*: " << std::is_const<const int*>::value << std::endl;
        std::cout << "int* const: " << std::is_const<int* const>::value << std::endl;
    }

    void TestTraitsSame() {
        std::cout << "is same: " << std::endl;
        std::cout << std::is_same<int, int>::value << std::endl;
        std::cout << std::is_same<int, unsigned int>::value << std::endl;
    }

    class A {};
    class B: public A {};
    void TestTraitsBaseOf() {
        std::cout << "is base of: " << std::endl;
        std::cout << std::is_base_of<A, B>::value << std::endl;
        std::cout << std::is_base_of<B, A>::value << std::endl;
    }

    void TestConvertTraits() {
        std::cout << std::is_same<const int, std::add_const<int>::type>::value << std::endl;
        std::cout << std::is_same<int, std::remove_const<const int>::type>::value << std::endl;
        std::cout << std::is_same<int&, std::add_lvalue_reference<int>::type>::value << std::endl;
        std::cout << std::is_same<int&&, std::add_rvalue_reference<int>::type>::value << std::endl;
        std::cout << std::is_same<int, std::remove_reference<int&>::type>::value << std::endl;
        std::cout << std::is_same<int, std::remove_reference<int&&>::type>::value << std::endl;
    }
}