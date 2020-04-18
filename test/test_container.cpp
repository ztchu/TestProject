#include "test_container.h"

#include <chrono>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <typeinfo>
#include <vector>


namespace test_container {
    void TestEmptyList() {
        std::list<int> list_int;
        list_int.push_back(3);
        list_int.pop_front();
        std::cout << *list_int.begin() << std::endl;
    }

    void TestEmptySet() {
        /*std::set<int*> set_test;
        int *ptr = new int(3);
        set_test.insert(ptr);
        set_test.insert(nullptr);*/

        int *ptr = new int(3);
        std::cout << *ptr << std::endl;
        delete ptr;
        int *qtr = new int(4);
        std::cout << *qtr << std::endl;
        if (ptr) {
            std::cout << *ptr << std::endl;
        }
    }

    void TestVectorIterator() {
        std::vector<int> vec{ 1, 2, 3, 4, 5 };
        auto iter = vec.begin();
        //vec.erase(++iter);
        vec.insert(iter, 6);
        std::cout << *iter << std::endl;
    }

    void TestListIterator() {
        std::list<int> ls{ 1, 2, 3, 4, 5 };
        auto iter = ls.begin();
        auto iter1 = ++iter;
        ls.erase(iter1);
        std::cout << *iter << std::endl;
        std::cout << *iter1 << std::endl;
    }

    void TestMapKey() {
        std::map<int, std::string> map_temp;
        map_temp.insert(std::make_pair(12, "qingya"));
        map_temp.insert(std::make_pair(12, "zijian"));
        map_temp.insert(std::make_pair(13, "sichan"));
        /*for (auto & iter : map_temp) {
            std::cout << iter.first << std::endl;
            std::cout << iter.second << std::endl;
        }*/
        auto iter = map_temp.rbegin();
        std::cout << iter->second << std::endl;
        std::cout << map_temp[14] << std::endl;
        std::cout << map_temp.size() << std::endl;
        map_temp.erase(14);
        std::cout << map_temp.size() << std::endl;

        std::map<uint16_t, std::unique_ptr<int>> cache;
        cache.insert(std::make_pair(13, new int(23)));
        std::cout << *cache[13] << std::endl;
        if (cache[14]) {
            std::cout << "okay." << std::endl;
        }
        else {
            std::cout << "nullptr." << std::endl;
        }
    }

    void TestMap() {
        std::map<int, std::string> map_data;
        for (auto i = 0; i < 10000; ++i) {
            map_data.emplace(i, "test");
        }

        auto start_time = std::chrono::steady_clock::now();
        for (auto iter = map_data.begin(); iter != map_data.end(); ++iter) {
            if (iter->first == 9999) {
                break;
            }
        }
        auto end_time = std::chrono::steady_clock::now();
        std::chrono::duration<double> com_diff = end_time - start_time;
        uint32_t totalTime = com_diff.count() * 1000;
        std::cout << "total time: " << totalTime;
    }

    void TestMoveVector() {
        std::vector<int> vec{ 1, 2, 3 };
        for (auto i = 0; i < vec.size(); ++i) {
            if (i == 1) {
                auto m = std::move(vec[i]);
                std::cout << m << std::endl;
            }
        }

        std::cout << vec.size() << std::endl;
        for (auto i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << std::endl;
        }
    }

    class TestVectorElement {
    public:
        TestVectorElement(std::size_t len) {
            data_ = new uint8_t[len];
        }
        ~TestVectorElement() {
            delete[] data_;
        }
    private:
        uint8_t *data_;
    };

    void  TestVectorPtr() {
        std::vector<std::unique_ptr<TestVectorElement>> vec;
        constexpr int vec_size = 3;
        for (int i = 0; i < vec_size; ++i) {
            vec.emplace_back(new TestVectorElement(i));
        }
        /*for (int i = 0; i < vec_size; ++i) {
            std::cout << "elem: " << *vec[i] << std::endl;
        }*/
        for (int i = 0; i < vec_size; ++i) {
            vec[i].reset();
        }
    }

    void TestQueue() {
        std::queue<int> first_q;
        std::queue<int> second_q;

        constexpr size_t len = 4;
        for (auto i = 0; i < len; ++i)
            first_q.push(i);

        second_q.swap(first_q);

        while (!second_q.empty()) {
            std::cout << second_q.front() << std::endl;
            second_q.pop();
        }
        std::cout << "------------------------";
        while (!first_q.empty()) {
            std::cout << first_q.front() << std::endl;
            first_q.pop();
        }
    }

    class MyObj {
    public:
        MyObj(int val):
        val_(val){
            std::cout << "Construct MyObj." << std::endl;
        }
        MyObj(const MyObj& obj) {
            val_ = obj.val_;
            std::cout << "Copy construct MyObj." << std::endl;
        }
        MyObj(MyObj&& obj) {
            val_ = obj.val_;
            std::cout << "Move construct MyObj." << std::endl;
        }
        ~MyObj() {
            std::cout << "Destruct MyObj." << std::endl;
        }
        int GetVal() const {
            return val_;
        }

    private:
        int val_;
    };

    MyObj ConstructVec(int n) {
        MyObj obj(n);
        return std::move(obj);
    }
    void TestReference() {
        MyObj&& vec = ConstructVec(10);
        std::cout << vec.GetVal() << std::endl;
        std::cout << typeid(vec).name() << std::endl;
    }
}