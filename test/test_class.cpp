#include "test_class.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>


class BaseA {
public:
    BaseA() {}
    virtual void Func() {
        std::cout << "BaseA::Func" << std::endl;
    }
    void Temp() {
        std::cout << "Begin to execute Temp()" << std::endl;
        age_ = 3;  // Crash takes place here
        std::cout << "End to execute Temp()" << std::endl;
    }
    virtual void Print() {
        std::cout << "BaseA" << std::endl;
    }
    ~BaseA() {}

private:
    int age_;
};

class BaseB {
public:
    BaseB() {}
    virtual ~BaseB() {}
};

class C : public BaseA, public BaseB {
public:
    C() {}
    void Func(int) {
        std::cout << "C::Func" << std::endl;
    }
private:
    void Print() {
        std::cout << "C" << std::endl;
    }

private:
    const char* m_name = "class C";
};

class D {
public:
    void Func() {
        std::cout << "D::Func(): " << a << std::endl;
        delete this;
        int a = 1;
        std::cout << a << std::endl;
    }
    ~D() {
        int a = 3;
        int b = 4;
        std::cout << a + b << std::endl;
    }
private:
    int a = 1;
};

namespace test_class {
    void TestDeleteThis() {
        D d;
        d.Func();
    }


    void TestSize() {
        std::cout << sizeof(C) << std::endl;
        BaseA *ptr = new C;
        ptr->Print();
    }

    void TestInvalidObject() {
        BaseA * ptr = nullptr;
        ptr->Temp(); // Work well.
        ptr->Func(); // Crash takes place here.
    }

    void TestDestructor() {
        D * ptr = nullptr;
        delete ptr;
    }

    void TestWildPointer() {
        D * ptr = new D();
        ptr->Func();
        delete ptr;
        int m = 3;
        int *ptr_int = new int(4);
        m = *ptr_int;
        if (ptr)
            ptr->Func();
        else {
            std::cout << "ptr is nullptr." << std::endl;
        }

        D* test_ptr = ptr;
        test_ptr->Func();
    }

    void TestLocalObject() {
        int num = 3;
        int *ptr = &num;
        delete ptr;  // no crash.
    }

    void TestNullptr() {
        auto ptr = reinterpret_cast<volatile char*>(NULL) + 57;
        std::cout << ptr << std::endl;
        *(reinterpret_cast<volatile char*>(NULL) + 57) = 0x21;
    }

    void TestNullptrVector() {
        std::vector<int *> vec;
        vec.push_back(new int(3));
        vec.push_back(nullptr); // Program will crash.
        vec.push_back(new int(4));
        std::for_each(vec.begin(), vec.end(), [](int *ptr) {
            std::cout << *ptr << std::endl;
        });
    }

    class MethodA {
    public:
        void Print(int number) {
            std::cout << number << std::endl;
            std::cout << data_ << std::endl;
        }
    private:
        int data_ = 4;
    };
    void TestMethodA(std::function<void(int)> fn) {
        fn(3);
    }
    void TestCallback() {
        MethodA a;
        //TestMethodA((std::function<void(int)>)(&MethodA::Print, &a));
    }

    class TestSharedPtr {
    public:
        TestSharedPtr() {
            d_ = std::make_shared<D>();
        }
        std::shared_ptr<D> GetSharedPtr() {
            return std::move(d_);
        }

    private:
        std::shared_ptr<D> d_;
    };

    void TestMovePtr() {
        TestSharedPtr ptr;
        ptr.GetSharedPtr()->Func();
    }

    void TestSharedAndUnique() {
        std::unique_ptr<int> uni_ptr = std::make_unique<int>(23);
        std::shared_ptr<int> shar_ptr = std::move(uni_ptr);
        std::cout << *shar_ptr << std::endl;
    }

    struct People {
        size_t age;
        std::string name;
    };

    /*People qing = {
        .age =  28,
        .name = "qing"
    };*/

    void TestStruct() {

    }
}
