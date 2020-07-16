#include "test_map.h"

#include <iostream>

void UnorderedMultiMap::Inert(int key, int val) {
    map_.insert({ key, val });
}

void UnorderedMultiMap::Find(int key) {
    auto count = map_.count(key);
    if (count < 1) {
        std::cout << "Can't find." << std::endl;
        return;
    }
    else if (count == 1) {
        auto iter = map_.find(key);
        std::cout << "key: " << iter->first << ", value: " << iter->second
            << std::endl;
        return;
    }
    else {
        auto iter = map_.equal_range(key);
        while (iter.first != iter.second) {
            std::cout << "key: " << iter.first->first
                << ", value: " << iter.first->second << std::endl;
            ++iter.first;
        }
    }
}

namespace test_map {
    void TestUnorderedMultiMap() {
        UnorderedMultiMap map;
        map.Inert(2, 4);
        map.Find(2);
        map.Inert(2, 5);
        map.Inert(2, 6);
        map.Find(2);
    }
}