#include <iostream>
#include <thread>
#include <queue>

class CleanCrew
{
    public:
    static std::queue<int> commands;
    static void clean()
    {
        printf("[CleanCrew] Received cleaning command!\n");
        std::this_thread::sleep_for(std::chrono::seconds(4));
        printf("[CleanCrew] Cleaning done!\n");
    }
    static void work()
    {
        while (true)
        {
            if(!commands.empty())
            {
                int &command = commands.front();
                switch(command)
                {
                    case 1:
                        clean();
                        commands.pop();
                    break;
                }
            }
        }
    }
};
std::queue<int> CleanCrew::commands;

class EngineCrew
{
    public:
    static std::queue<int> commands;

    static void full_speed_ahead()
    {
        printf("[EngineCrew] Received Full speed ahead command!\n");
        std::this_thread::sleep_for(std::chrono::seconds(4));
        printf("[EngineCrew] Full speed ahead done!\n");
    }
    static void stop()
    {
        printf("[EngineCrew] Received stop command!\n");
        std::this_thread::sleep_for(std::chrono::seconds(4));
        printf("[EngineCrew] Stopping done!\n");
    }
    static void work()
    {
        while (true)
        {
            if(!commands.empty())
            {
                int &command = commands.front();
                switch(command)
                {
                    case 2:
                        full_speed_ahead();
                        commands.pop();
                    break;
                    case 3:
                        stop();
                        commands.pop();
                    break;
                }
            }
        }
    }
};
std::queue<int> EngineCrew::commands;

void captain()
{
    CleanCrew clean_crew = CleanCrew();
    EngineCrew engine_crew = EngineCrew();

    int command = 0;
    std::thread clean_crew_thread(clean_crew.work);
    std::thread engine_crew_thread(engine_crew.work);

    while(command != 100)
    {
        std::cin >> command;
        switch (command)
        {
            case 1: 
            {
                CleanCrew::commands.push(1);
            }
            break;
            case 2: 
            {
                EngineCrew::commands.push(2);
            }
            break;
            case 3:
            { 
                EngineCrew::commands.push(3);
            }
            break;
            case 100:
                printf("Take a break crew!\n");
            break;
            default:
                printf("Invalid order\n");
        }
        printf("[Captain] Thinking about next task!\n");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    clean_crew_thread.join();
    engine_crew_thread.join();
}

int main(void )
{
    captain();
}