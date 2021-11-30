#include <iostream>
#include <ctime>
#include <vector>

struct task
{
    std::string name;
    time_t start;
    time_t duration;
};

void begin(std::vector<task>& tasks)
{
    std::string input;
    if(!tasks.empty()&&tasks.back().duration==0)
        tasks.back().duration=(time_t)(std::difftime(std::time(nullptr), tasks.back().start));

    std::cout << "Type task name: ";
    std::cin >> input;
    tasks.push_back({input, std::time(nullptr)});
}

void end(std::vector<task>& tasks)
{
    if(!tasks.empty()&&tasks.back().duration==0)
        tasks.back().duration=(time_t)(std::difftime(std::time(nullptr), tasks.back().start));
}

void status(std::vector<task>& tasks)
{
    for(int i=0;i<tasks.size();i++)
    {
        std::cout << tasks[i].name << ": ";
        if(!tasks[i].duration)
        {
            std::cout << (time_t)(std::difftime(std::time(nullptr), tasks.back().start)) << std::endl;
        }
        else
            std::cout << tasks[i].duration << std::endl;
    }
}

int main()
{
    std::vector<task> tasks;

    std::string input;
    do {
        std::cout << "Type command: ";
        std::cin >> input;

        if(input == "begin")
            begin(tasks);

        else if(input=="end")
            end(tasks);

        else if(input=="status")
            status(tasks);

    }
    while(input != "exit");

    return 0;
}
