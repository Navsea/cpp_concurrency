//#include "queue.hpp"
#include <mutex>
#include <queue>
#include <condition_variable>
#include <memory>
#include <thread>
#include <chrono>

template <typename T>
class QueueSafe {
public:
    std::mutex m;
    std::condition_variable cv;
    std::queue<std::shared_ptr<T>> q;

    void push(T value)
    {
        std::lock_guard<std::mutex> lg(m);
        q.push(std::make_shared<T>(value));
        printf("Pushed a value of: %d\n", value);
        cv.notify_one();
    }

    bool pop(T &ref)
    {
        std::lock_guard<std::mutex> lg(m);
        ref = *(q.front());
        q.pop();
        return true;
    }

    bool wait_pop(T &ref)
    {
        std::unique_lock<std::mutex> ul(m, std::defer_lock);
        printf("Waiting in front of ul\n");
        cv.wait(ul, [this]{ return !q.empty(); });
        printf("condition variable signaled validly\n");
        ref = *(q.front());
        q.pop();
        return true;
    }

    bool empty()
    {
        std::lock_guard<std::mutex> lg(m);
        return q.empty();
    }
};

int main()
{
    int my_int = 0;
    QueueSafe<int> qs;
    
    std::thread th1(&QueueSafe<int>::wait_pop, &qs, std::ref(my_int));

    std::this_thread::sleep_for(std::chrono::seconds(2));

    qs.push(1);

    th1.join();
    return 0;
}

