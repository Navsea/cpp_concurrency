#pragma once

#include <thread>

class thread_guard {
    std::thread &t;

public:
    explicit thread_guard(std::thread &_t): t(_t)
    {}
    ~thread_guard()
    {
        if (t.joinable())
        {
            t.join();
        }
    }

    // do not allow copying of threads
    thread_guard(thread_guard &const) = delete;
    thread_guard& operator=(thread_guard &const) = delete;
};