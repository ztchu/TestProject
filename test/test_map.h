#pragma once

#include<unordered_map>

class UnorderedMultiMap {
public:
    void Inert(int key, int val);
    void Find(int key);

private:
    std::unordered_multimap<int, int> map_;
};

namespace test_map{
    void TestUnorderedMultiMap();
}
