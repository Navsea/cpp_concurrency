#include <iostream>
#include <thread>

void test()
{
    printf("Hello from test \n");
}
void functionA()
{
    std::thread threadC(test);
    printf("Hello from functionA \n");
    threadC.join();
}
void functionB()
{
    printf("Hello from functionB \n");
}

int main()
{
    std::thread threadA(functionA);
    std::thread threadB(functionB);

    printf("Hello from main \n");

    threadA.join();
    threadB.join();
}