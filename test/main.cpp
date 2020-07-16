#include <iostream>
#include <string>

#include <assert.h>
#include "test_algorithm.h"
#include "test_class.h"
#include "test_container.h"
#include "test_function.h"
#include "test_map.h"
#include "test_math.h"
#include "test_pointer.h"
#include "test_string.h"
#include "test_template.h"
#include "test_thread.h"
#include "test_time.h"
#include "test_typetraits.h"
#include "test_operator.h"


int main() {
    //test_string::TestHash();
    //test_thread::TestLambda();
    //test_container::TestEmplace();
    //test_class::TestVirtualFunc();
    //test_string::TestStringstream();
    //test_thread::TestThreadJoin();
    //test_container::TestVectorEmpty();
    //test_class::TestRealC();
    //assert(0);
    //test_chrono::TestTimepoint();
    //test_pointer::TestDeleteNullptr();
    //test_algorithm::TestAllOf();
    // test_function::TestBind();
    //test_operator::TestXor();
    //test_map::TestUnorderedMultiMap();
    test_template::TestOptional();
    //test_typetraits::TestConvertTraits();
    system("pause");
}
