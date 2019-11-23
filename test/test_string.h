#pragma once

namespace test_string {

    // Set const char* ptr = nullptr, and asign to string will cause crash.
    void TestNullptrToString();

    void TestInvalidReference();

    void TestCrash();

    void TestReadString();

    void TestEmptyString();
}