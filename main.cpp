#include <iostream>

#include "commandCore.h"
#include "messages.h"
#include "paths.h"
#include "helper.h"
#include "dataStore.h"

int main()
 {
    std::cout << "\033[0;32m";
    Helper().printTxt(LOGO_PATH);
    std::cout << "\033[0m" << std::endl;
    
    std::cout << WELCOME_MESSAGE << std::endl;
    while (true)
    {
        std::string str {};
        std::getline(std::cin, str);
        if (str != std::string()) 
        {
            CommandCore().commandHandler(str);
        }
    }
}
