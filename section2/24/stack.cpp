#include <stack>
#include <mutex>
#include <iostream>

// this in fact limits parallel access
// there can still be a race condition between empty() and pop(), see client function
template <typename T>
class stack_safe 
{
    std::stack<T> stk;
    std::mutex m;

public:
    void push(T element)
    {
        std::lock_guard<std::mutex> lg(m);
        stk.push(element);
    }
    void pop()
    {
        std::lock_guard<std::mutex> lg(m);
        stk.pop();
    }
    T& top()
    {
        std::lock_guard<std::mutex> lg(m);
        return stk.top();
    }
    bool empty()
    {
        std::lock_guard<std::mutex> lg(m);
        return stk.empty();
    }
};

// racing scenario
// first thread first checks empty, not empty, but second thread then pops an element before top()
int main()
{
    stack_safe<int> stk;
    stk.push(1);

    if (!stk.empty())
    {
        int value = stk.top();
        std::cout << "value -- " << value << std::endl;
        stk.pop();
    }
    return 0;
}