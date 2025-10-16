#include <iostream>

#include "commands/commandCore.h"
#include "logic/helper.h"
#include "database/dataStore.h"

int main()
 {
    Descriptor des("qwerty,Name(STRING[NONE]),gerafe(INT),fdfdf(INT[x<16])");
    DataStore& store = DataStore::getInstance();
    store.descriptor = des;
    
    std::cout << "\033[0;32m";
    Helper().printTxt("content/logo.txt");
    std::cout << "\033[0m" << std::endl;
    
    std::cout << "Welcome in MNKSQL. To see all commands type: \"HELP\"" << std::endl;
    while (true)
    {
        std::string str {};
        std::getline(std::cin, str);
        if (str != "") 
        {
            CommandCore().commandHandler(str);
        }
    }
}
