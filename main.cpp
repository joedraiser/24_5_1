#include <iostream>
#include <ctime>
#include <vector>

struct task
{
    std::string name;
    time_t start;
    time_t duration;
};

int main()
{
    std::vector<task> tasks;

    std::string input;
    do {
        std::cout << "Type command: ";
        std::cin >> input;

        if(input == "begin")
        {
            if(!tasks.empty()&&tasks.back().duration==0)
                tasks.back().duration=(time_t)(std::difftime(std::time(nullptr), tasks.back().start));

            std::cout << "Type task name: ";
            std::cin >> input;
            tasks.push_back({input, std::time(nullptr)});
        }
        else if(input=="end")
        {
            if(tasks.back().duration==0)
                tasks.back().duration=(time_t)(std::difftime(std::time(nullptr), tasks.back().start));
        }
        else if(input=="status")
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
    }
    while(input != "exit");


    return 0;
}
