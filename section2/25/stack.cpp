#include <stack>
#include <mutex>
#include <iostream>
#include <memory>

// solutions to previous racing conditions
// combine top and pop functions in one, but still there can be racing conditions
// this happens because the pointer is deleted first, then the value is returned
// if the value is large, then it could be that the value was only partly retrieved
// when returning, that would try to deref the pointer (not sure if that is correct)
// when returning, a copy could be required, when obj is large, we could run out of memory
// 1 you also store just pointers to memory
// 2 let the user provide the reference and return the shared ptr
template <typename T>
class stack_safe 
{
    std::stack<std::shared_ptr<T>> stk;
    std::mutex m;

public:
    void push(T element)
    {
        std::lock_guard<std::mutex> lg(m);
        stk.push(std::make_shared<T>(element));
    }
    // here we check the empty(), this prevents the race conditions when user first 
    // checks empty and then pops()
    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> lg(m);
        if (stk.empty())
        {
            throw std::runtime_error("stack is empty!");
        }
        std::shared_ptr<T> res(stk.top());
        stk.pop();
        return res;
    }
    void pop(T& value)
    {
        std::lock_guard<std::mutex> lg(m);
        if (stk.empty()) throw std::runtime_error("stack is empty!");
        // note that youy have to get the value from the stack!
        // then assign that to the reference
        value = *(stk.top());
        stk.pop();
    }
    std::shared_ptr<T> top()
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