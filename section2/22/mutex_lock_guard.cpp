#include <iostream>
#include <mutex>

class data_object 
{
public:
    int value = 1;
};

// This class can execute a function by using lock guard first
// but the function can still access the data itself, by getting ref to it
class data_wrapper {
    data_object protected_data;
    std::mutex m;

public:
    template <typename function>
    void do_some_work(function f)
    {
        std::lock_guard<std::mutex> lg(m);
        f(protected_data);
    }
};

data_object *unprotected_data;
void malicious_function(data_object &data)
{
    unprotected_data = &data;
    unprotected_data->value = 5;
    printf("hacked value: %d", unprotected_data->value);
}

int main(void )
{
    data_wrapper wrapper;
    wrapper.do_some_work(malicious_function);
}