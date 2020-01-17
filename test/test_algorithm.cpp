#include "test_algorithm.h"

#include <algorithm>
#include <map>
#include <iostream>
#include <vector>

namespace test_algorithm {
    void TestBinarySearch() {
        std::map<int, int> data;
        for (auto i = 0; i < 10; ++i) {
            data.emplace(i, i * i + 1);
        }

        int mid = 0;
        int target = 50;
        for (int low = 0, high = data.size(); low <= high;) {
            auto iter = data.begin();
            mid = (low + high) / 2;
            std::advance(iter, mid);
            if (iter == data.end()) {
                break;
            }
            if (iter->second < target) {
                low = mid + 1;
            }
            else if (iter->second > target){
                high = mid - 1;
            }
            else {
                break;
            }
        }

        std::cout << mid << std::endl;
        data.erase(data.begin(), data.begin());
        std::cout << data.begin()->second << std::endl;
    }

    void TestAllOf() {
        std::vector<int> vec{ 1, 2, 3, 4 };
        int array[] = { 5, 9, 7, 11 };
        if (!std::all_of(vec.begin(), vec.end(), [](int i) {return i > 2; })) {
            std::cout << "Not all number are greater than 2." << std::endl;
        }
        if (std::all_of(std::begin(array), std::end(array), [](int i) { return i % 2; })) {
            std::cout << "All data are odd number." << std::endl;
        }
        if (std::none_of(std::begin(array), std::end(array), [](int i) { return i < 4; })) {
            std::cout << "None of them is less than 4." << std::endl;
        }
    }
}