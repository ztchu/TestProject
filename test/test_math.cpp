#include "test_math.h"

#include <cmath>
#include <iostream>


namespace test_math {
    void TestCeil() {
        float input = 0.001;
        std::cout << std::ceil(input) << std::endl;
        std::cout << std::floor(input) << std::endl;
    }

    class Solution {
    public:
        bool isEqual(char a, char b) {
            if (a == b) {
                return true;
            }
            if (isalpha(a) && isalpha(b)) {
                if ((a - b == 'a' - 'A') || (b - a == 'a' - 'A')) {
                    return true;
                }
            }
            return false;
        }
        bool isPalindrome(std::string s) {
            if (s.length() < 2) {
                return true;
            }
            for (int i = 0, j = s.length() - 1; i < j;) {
                if (isalnum(s[i]) && isalnum(s[j])) {
                    if (isEqual(s[i], s[j])) {
                        ++i;
                        --j;
                        continue;
                    }
                    else {
                        return false;
                    }
                }
                if (!isalnum(s[i])) {
                    ++i;
                }
                if (!isalnum(s[j])) {
                    --j;
                }
            }
            return true;
        }
    };

    void TestMathAlpha() {
        Solution so;
        auto ans = so.isPalindrome("0P");
        if (ans) {
            std::cout << "true";
        }
        else {
            std::cout << "false";
        }
    }
}
