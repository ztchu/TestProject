#include "test_function.h"


#include <functional>
#include <iostream>

using namespace std::placeholders;

typedef void(*MLogCallBack)(const char *file, int line, const char *func, int severity, const char *content);

namespace test_function {
    void LogCallback(const char* file, int line, const char* func, int severity, const char* content, int hash) {
        std::cout << file << std::endl;
    }

    void SetLogCallback(MLogCallBack callback) {
        callback("a", 1, "b", 2, "c");
    }

    void TestBind() {
        int hash = 123;
        MLogCallBack callback = //std::bind(&LogCallback, _1, _2, _3, _4, _5, 123); 
            [](const char *file, int line, const char *func, int severity, const char *content) {

        };
        callback("a", 1, "b", 2, "c");
    }

}

