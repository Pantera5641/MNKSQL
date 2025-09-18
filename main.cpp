#include <iostream>

#include "logic/helper.cpp"
#include "commands/command_core.cpp"

int main()
{
    std::cout << "\033[0;32m";
    Helper().PrintTxt("content/logo.txt");
    std::cout << "\033[0m" << std::endl;

    std::cout << "Welcome in MNKSQL. To see all commands type: \"HELP\"" << std::endl;
    while (true)
    {
        std::string str {};
        std::getline(std::cin, str);

        Command_Core().commandHandler(str);
    }
}
