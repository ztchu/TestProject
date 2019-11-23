#include "test_thread.h"

#include <atomic>
#include <functional>
#include <future>
#include <iostream>
#include <mutex>
#include <string>
#include <Windows.h>

namespace test_thread {
    std::mutex mutex;

    void DoWork() {
        try {
            int a = 0;
            //throw - 1;
            std::cout << "Print a message." << std::endl;
        }
        catch (...) {
            std::lock_guard<std::mutex> lock(mutex);
            std::cout << "exception." << std::endl;
        }
    }

    void Mediate() {
        std::lock_guard<std::mutex> lock(mutex);
        DoWork();
    }

    void Test() {
        std::thread worker(Mediate);
        DWORD result = ::SetThreadIdealProcessor(worker.native_handle(), 3);
        //worker.detach();
        std::cout << "Call Test()" << std::endl;
        if (worker.joinable())
            worker.join();
        std::mutex temp_mutex;
        temp_mutex.lock();
        int a = 1;
        temp_mutex.unlock();
    }
    
    int TestAtomic() {
        std::atomic<int> counter = 0;
        /*for (int i = 0; i < 100000000; ++i) {
            ++counter;
        }*/
        std::this_thread::sleep_for(std::chrono::seconds(5));
        return counter;
    }
    
    void TestFuture() {
        // The task is launched immediately in a seperate thread.
        std::future<int> result = std::async(std::launch::async, TestAtomic);
        std::cout << "TestFuture" << std::endl;
        while (true) {
            if (result.valid() && 
                result.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
                std::cout << result.get() << std::endl;
                break;
            }
            std::cout << "Still working." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        
        std::cout << "End.";
    }

    void TestFutureException() {
        std::future<int> future = std::async(std::launch::async, []() {
            throw std::runtime_error("Catch in main.");
            return 0;
        });

        try {
            if (future.valid()) {
                int ret = future.get();
            }
        }
        catch (const std::runtime_error & e) {
            std::cout << "Async task threw exception: " << e.what() << std::endl;
        }
        std::cout << "std::thread::hardware_concurrency: " << std::thread::hardware_concurrency();
    }

    std::function<void()> TestDestructReferenceWorker() {
        std::string str("1ing");
        std::function<void()> func = [&]() {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << str;
        };
        return std::move(func);
    }

    void TestDestructReference() {
        auto func = TestDestructReferenceWorker();
        func();
    }

    std::vector<int> vec_int{ 1, 2, 3, 4, 5, 6 };
    void TestIterInvalidWorker() {
        for (int i = 0; i < 10000; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            vec_int.push_back(i);
        }
    }

    void TestIterInvalid() {
        std::thread td(TestIterInvalidWorker);
        for (auto iter = vec_int.begin(); iter != vec_int.end(); ++iter) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            std::cout << *iter << std::endl;
        }
        if (td.joinable()) {
            td.join();
        }
    }

    std::mutex g_mutex;
    volatile int g_counter(0);
    void Add10KNum() {
        for (auto i = 0; i < 10000; ++i) {
            if (g_mutex.try_lock()) {
            //{
                //g_mutex.lock();
                ++g_counter;
                g_mutex.unlock();
            }
        }
    }

    void TestMutex() {
        std::vector<std::thread> threads;
        for (auto i = 0; i < 10; ++i) {
            threads.emplace_back(Add10KNum);
        }

        std::cout << "thread number: " << threads.size() << std::endl;
        for (auto &thread : threads) {
            if (thread.joinable()) {
                thread.join();
            }
        }
        std::cout << "counter: " << g_counter << std::endl;
    }

    uint32_t num = 0;
    void TestThreadOne() {
        while (1) {
            ++num;
            //std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    void TestThreadTwo() {
        while (1) {
            ++num;
            //std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
    void TestThread() {
        std::thread t1(TestThreadOne);
        std::thread t2(TestThreadTwo);
        if (t1.joinable()) {
            t1.join();
        }
        if (t2.joinable()) {
            t2.join();
        }
    }

    void ThreadFuncTestJoin() {
        std::cout << "ThreadFuncTestJoin" << std::endl;
    }
    void TestThreadJoin() {
        /*std::thread td(ThreadFuncTestJoin);
        if (td.joinable()) {
            td.join();
        }

        td = std::move(std::thread(ThreadFuncTestJoin));
        if (td.joinable()) {
            td.join();
        }*/
        std::thread td1;
        // For uninitialized thread objects, calling join directly will cause crash.
        if (td1.joinable())
        td1.join();
    }
}