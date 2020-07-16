#include "test_template.h"

#include <functional>
#include <iostream>
#include <optional>

namespace test_template {
    void TestTemplate() {
        int a = 1;
        float b = 2.0;
        auto c = add<decltype(a + b)>(a, b);
        c = add_tail(2, 3.0);
        std::cout << c << std::endl;

        map_int_t map_int;
        map_str_t map_str;

        Type<> int_val{ 1 };
        std::cout << int_val.a << std::endl;

        Func(1);

        Type<float> float_val{ 2.0 };
        std::cout << float_val.a << std::endl;

        Func(3.0);

        int* ptr = new int(23 );
        std::cout << *ptr << std::endl;

        int* arr = new int[3]{ 1, 2, 3 };
        std::cout << *(arr + 2) << std::endl;
    }

    struct ST {
        int x;
        ST(int x) {
            x = x;
        }
        virtual void F() {}
    };

    ST s{ 1 };

    std::initializer_list<int> list{ 1, 2, 3 };

    std::initializer_list<int> ReturnIniList() {
        return { 1, 2, 3 };
    }

    int a = 1.1;

    void TestReturnIniList() {
        auto ans = ReturnIniList();
        for (auto iter = ans.begin(); iter != ans.end(); ++iter) {
            std::cout << *iter << std::endl;
        }
    }

    void Test0() {
        std::cout << "void" << std::endl;
    }
    int Test1(int x) {
        std::cout << "x: " << x << std::endl;
        return x;
    }
    void TestForward() {
        FuncWrapper(Test0);
        FuncWrapper(Test1, 1);
    }

    void TestEnableA() {
        FuncEnable(4.0);
        FuncEnable('c');
        FuncEnable(24);
        // FuncEnable("hello");
    }

    void TestSizeof() {
        Sizeof();
        Sizeof(1, 2.0);
        Sizeof("qing", 2, 3.0);
    }

    template<typename T>
    void PrintArgs(T t) {
        std::cout << t << std::endl;
    }
    template<typename T, typename... Args>
    void PrintArgs(T head, Args... rest) {
        std::cout << head << std::endl;
        PrintArgs(rest...);
    }
    void TestPrintArgs() {
        PrintArgs(1, 2, "QINGYA");
        //PrintArgs();
    }

    void TestTuple() {
        std::tuple<int> tp_int = std::make_tuple(1);
        std::tuple<int, double> tp_int_d = std::make_tuple(2, 2.0);
        std::cout << std::get<0>(tp_int) << std::endl;
        std::cout << std::get<int>(tp_int_d) << " " << std::get<double>(tp_int_d);
    }

    template<typename T, typename... Args>
    T* Instance(Args... args) {
        return new T(args...);
    }

    template<typename T, typename... Args>
    T* InstanceA(Args... args) {
        return new T(std::forward<Args>(args)...);
    }
    class A {
    public:
        A(int a) {
            a_ = a;
        }
        int a_;
    };
    class B {
    public:
        B(int a, int b) {
            a_ = a;
            b_ = b;
        }
        int a_;
        int b_;
    };
    void TestArgs() {
        A* a = InstanceA<A>(1);
        std::cout << a->a_ << std::endl;
        B* b = InstanceA<B>(1, 2);
        std::cout << b->a_ << " " << b->b_ << std::endl;
    }

    void TestOptional() {
        std::optional<int> op;
        if (op) {
            std::cout << *op << std::endl;
        }

        std::optional<int> op1 = 1;
        if (op1) {
            std::cout << *op1 << std::endl;
        }
    }
}