#include <iostream>

#include "logic/helper.cpp"
#include "logic/parser.cpp"
#include "logic/path.cpp"
#include "logic/smartFile.cpp"

#include "commands/command_core.cpp"
#include "commands/commandDb(t).cpp"

#include "database/database.cpp"
#include "database/student22/student22.cpp"

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
