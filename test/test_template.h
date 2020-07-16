#pragma once

#include <iostream>
#include <map>
#include <string>

namespace test_template {
    template<typename R, typename T, typename U>
    R add(T t, U u) {
        return t + u;
    }

    template<typename T, typename U>
    auto add_tail(T t, U u)->decltype(t + u) {
        return t + u;
    }

    typedef std::map<std::string, int> map_int_t;
    typedef std::map<std::string, std::string> map_str_t;

    typedef void (*func_t)(int, int);
    using func_t_a = void (*)(int, int);

    template<typename T = int>
    struct Type {
        int a;
    };

    template<typename T = int>
    void Func(T val) {
        std::cout << val << std::endl;
    }

    template<typename F, typename... Args>
    inline auto FuncWrapper(F&& f, Args&& ... args) -> decltype(f(std::forward<Args>(args)...)) {
        return f(std::forward<Args>(args)...);
    }

    void TestTemplate();
    void TestReturnIniList();
    void TestForward();

    template<typename T>
    typename std::enable_if<std::is_arithmetic<T>::value>::type FuncEnable(T t) {
        std::cout << typeid(T).name() << std::endl;
    }
    void TestEnableA();

    template<typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, std::string>::type ToString(T& t) {
        return std::to_string(t);
    }

    template<typename T>
    typename std::enable_if<std::is_same<T, std::string>::value, std::string>::type ToString(T& t) {
        return t;
    }

    template<typename... T>
    void Sizeof(T... args) {
        std::cout << sizeof...(args) << std::endl;
    }
    void TestSizeof();

    
    void TestPrintArgs();

    void TestTuple();

    void TestArgs();

    void TestOptional();
}