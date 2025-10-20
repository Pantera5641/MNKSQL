#include <iostream>

#include "commandCore.h"
#include "helper.h"
#include "dataStore.h"

int main()
 {
    std::cout << "\033[0;32m";
    Helper().printTxt("data/logo.txt");
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
