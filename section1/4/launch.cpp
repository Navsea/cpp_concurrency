#include <iostream>
#include <thread>

/*
A thread can use:
1. Functions
2. Lambda expressions
3. Functors (classes with () operator)
*/

void foo()
{
    printf("Hello from foo - %d\n", std::this_thread::get_id());
}

class callable_class {
    public:
    void operator()() 
    {
        printf("Hello from class with function call operator - %d\n", std::this_thread::get_id());
    }
};

int main()
{
    std::thread thread1(foo);

    callable_class obj;
    std::thread thread2(obj);

    std::thread thread3([]
    {
        printf("Hello from lambda - %d\n", std::this_thread::get_id());
    });

    printf("Hello from main - %d\n", std::this_thread::get_id());

    thread1.join();
    thread2.join();
    thread3.join();
    return 0;
}