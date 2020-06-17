#include <iostream>
#include <string>

#include <assert.h>
#include "test_algorithm.h"
#include "test_class.h"
#include "test_container.h"
#include "test_function.h"
#include "test_math.h"
#include "test_pointer.h"
#include "test_string.h"
#include "test_thread.h"
#include "test_time.h"


int main() {
    //test_string::TestStringstream();
    //test_thread::TestThreadJoin();
    //test_container::TestVectorEmpty();
    //test_class::TestRealC();
    //assert(0);
    //test_chrono::TestTimepoint();
    //test_pointer::TestDeleteNullptr();
    //test_algorithm::TestAllOf();
    // test_function::TestBind();
    test_math::TestCeil();
    std::cout << "Hello world." << std::endl;
    system("pause");
}