#include "test_string.h"

#include <iostream>
#include <string>
#include <vector>

namespace test_string {
    void TestNullptrToString() {
        std::string name;
        const char* ptr = nullptr;
        name = ptr;
    }

    // Invalid reference cause crash.
    /*void TestInvalidReference() {
        std::vector<std::string> vec;
        vec.push_back("string1");
        std::string & str1 = vec[0];
        std::vector<std::string>::iterator iter = vec.begin();
        vec.push_back("string2");
        std::cout << str1 << std::endl;
        std::cout << *iter << std::endl;
    }*/

    void TestInvalidReference() {
        std::vector<int> vec;
        vec.push_back(4);
        int & str1 = vec[0];
        std::vector<int>::iterator iter = vec.begin();
        vec.push_back(3);
        std::cout << str1 << std::endl;
        std::cout << *iter << std::endl;
    }

    void TestCrash() {
        //memset(static_cast<char*>(0), 1, 100);
        //int *ptr = reinterpret_cast<int*>(0x1234567810);
        //std::cout << *ptr << std::endl;
        int *ptr1 = new int(3);
        std::cout << *ptr1 << std::endl;
        delete ptr1;
        //std::cout << *ptr1 << std::endl;
        //const char *str = "hello";
        //*str = 'h';
        int *q = nullptr;
        *q;
    }

    void TestReadString() {
        int a = 3;
        printf("%s \n", a);
    }

    void TestEmptyString() {
        std::string str_empty;
        str_empty = "qingya" + str_empty + "test";
        std::cout << str_empty << std::endl;
    }
}