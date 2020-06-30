#include "test_container.h"

#include <chrono>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
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

    void TestMapBase() {
        std::map<int, std::string> map_data;
        map_data.insert({ 1, "qingya" });
        map_data.insert({ 2, "zijian" });
        map_data.insert(map_data.rbegin().base(), { 3, "sichan" });
        //map_data.erase(map_data.rbegin());
        for (auto& item : map_data) {
            std::cout << item.first << ", " << item.second << std::endl;
        }
    }
}