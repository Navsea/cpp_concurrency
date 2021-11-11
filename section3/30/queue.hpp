#include <mutex>
#include <queue>


template<typename T>
class QueueSafe {
public:
    std::mutex m;
    std::condition_variable cv;
    std::queue<std::shared_ptr<T>> q;

    QueueSafe();
    QueueSafe(QueueSafe const &other_QueueSafe);
    void push(T value);

    // set the value in the ref passed the user
    bool pop(T& ref);
    // return a shared ptr to the object
    //std::shared_ptr<T> pop();

    bool wait_pop(T& ref);
    //std::shared_ptr<T> wait_pop();

    bool empty();
};