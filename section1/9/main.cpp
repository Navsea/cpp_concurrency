#include <iostream>
#include <thread>

class CleanCrew
{
    public:
    static void clean()
    {
        printf("[CleanCrew] Received cleaning command!\n");
        std::this_thread::sleep_for(std::chrono::seconds(2));
        printf("[CleanCrew] Cleaning done!\n");
    }
};

class EngineCrew
{
    public:
    static void full_speed_ahead()
    {
        printf("[EngineCrew] Received Full speed ahead command!\n");
        std::this_thread::sleep_for(std::chrono::seconds(2));
        printf("[EngineCrew] Full speed ahead done!\n");
    }
    static void stop()
    {
        printf("[EngineCrew] Received stop command!\n");
        std::this_thread::sleep_for(std::chrono::seconds(2));
        printf("[EngineCrew] Stopping done!\n");
    }
};

void captain()
{
    CleanCrew clean_crew = CleanCrew();
    EngineCrew engine_crew = EngineCrew();

    int command = 0;
    while(command != 100)
    {
        std::cin >> command;
        switch (command)
        {
            case 1: 
            {
                std::thread clean(clean_crew.clean);
                clean.detach();
            }
            break;
            case 2: 
            {
                std::thread full_speed(engine_crew.full_speed_ahead);
                full_speed.join();
            }
            break;
            case 3:
            { 
                std::thread stop(engine_crew.stop);
                stop.join();
            }
            break;
            case 100:
                printf("Take a break crew!\n");
            default:
                printf("Invalid order\n");
        }
        printf("[Captain] Thinking about next task!\n");
    }
}

int main(void )
{
    captain();
}