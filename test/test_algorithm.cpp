#include "test_algorithm.h"


#include <map>
#include <iostream>

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
}