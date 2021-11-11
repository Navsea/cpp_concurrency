#include <mutex>
#include <thread>

class BankAccount
{
    double balance;
    std::string name;
    std::mutex m;
public:
    BankAccount() {};
    BankAccount(double _balance, std::string _name): balance(_balance), name(_name) {}
    BankAccount(const BankAccount&) = delete;
    BankAccount& operator=(const BankAccount&) = delete;

    void transfer(BankAccount& from, BankAccount& to, double amount)
    {
        // define a unique lock, but dont lock it yet
        std::unique_lock<std::mutex> ul1(from.m, std::defer_lock);
        std::unique_lock<std::mutex> ul2(to.m, std::defer_lock);

        // one we have two unique locks, lock both at the same time
        std::lock(ul1, ul2);

        from.balance -= amount;
        to.balance += amount;

        printf("balance from: %d, balance to: %d \n", int(from.balance), int(to.balance));
    }
};

int main()
{
    BankAccount mine = BankAccount(2000, "Mine");
    BankAccount andere1 = BankAccount(1000, "Andere1");
    BankAccount andere2 = BankAccount(800, "Andere2");

    // so reference the function via class, and then pass the ref to the object you want the function to be called
    std::thread thread1(&BankAccount::transfer, std::ref(mine), std::ref(mine), std::ref(andere1), 100.0);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::thread thread2(&BankAccount::transfer, &mine, std::ref(mine), std::ref(andere2), 500.0);

    thread1.join();
    thread2.join();

    return 0;
}