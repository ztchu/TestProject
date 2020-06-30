#include <iostream>
#include <string>

#include <assert.h>
#include "test_algorithm.h"
#include "test_class.h"
#include "test_container.h"
#include "test_function.h"
#include "test_pointer.h"
#include "test_string.h"
#include "test_thread.h"
#include "test_time.h"
#include "test_operator.h"

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
int main() {
    Solution so;
    auto ans = so.isPalindrome("0P");
    if (ans) {
        std::cout << "true";
    }
    else {
        std::cout << "false";
    }
    //test_string::TestEmptyString();
    //test_thread::TestLambda();
    //test_container::TestMapBase();
    //test_class::TestVirtualFunc();
    //assert(0);
    //test_chrono::TestTimepoint();
    //test_pointer::TestDeleteNullptr();
    //test_algorithm::TestBinarySearch();
    // test_function::TestBind();
    //test_operator::TestXor();
    std::cout << "Hello world." << std::endl;
    system("pause");
}