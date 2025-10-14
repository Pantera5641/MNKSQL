#include <iostream>

#include "logic/helper.cpp"
#include "logic/parser.cpp"
#include "logic/path.cpp"
#include "logic/smartFile.cpp"

#include "commands/command_core.cpp"
#include "commands/commandDb.cpp"

#include "database/container.cpp"
#include "database/dataStore.cpp"
#include "database/descriptor.cpp"


int main()
{
    Descriptor des("qwerty;Name(string[none]);gerafe(int);fdfdf(int[x<16])");
    Container cont = des.createContainer("123;123;123;123");
    DataStore& store = DataStore::getInstance();
    store.descriptor = des;
    store.database.push_back(cont);
    DataStore& store2 = DataStore::getInstance();

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
