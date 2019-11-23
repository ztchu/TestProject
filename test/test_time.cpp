#include "test_time.h"

#include <iostream>

namespace test_chrono {
    void TestTimepoint() {
        auto start = std::chrono::steady_clock::now();

        uint64_t ans = 0;
        for (auto i = 0; i < 10000000; ++i) {
            ans += 1;
        }
        std::cout << ans << std::endl;
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << "diff time" << diff.count() << std::endl;
        std::cout << "duration cast : " << std::chrono::duration_cast<
            std::chrono::milliseconds>(end - start).count() << std::endl;
    }
}