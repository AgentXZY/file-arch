#include <windows.h>
#include "commands/ShowTreeCommand.h"
#include <iostream>
#include <string>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    std::string command;

    std::cout << "filearch> ";
    std::getline(std::cin, command);

    if(command == "tree")
    {
        ShowTreeCommand::execute();
    }
    else
    {
        std::cout << "Unknown command\n";
    }

    return 0;
}