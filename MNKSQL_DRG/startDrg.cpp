#include "startDrg.h"

extern std::string globalLanguage;


void startDrg()
{
    std::string input {};
    MenuType menuType {MenuType::Main};

    while (true) 
    {   
        show("MNKSQL_DRG/data/logo.txt", "\033[0;31m");

        showMenu(menuType, globalLanguage);
        std::cin >> input;

        if (isDigit(input)) 
        {
            menuType = execute(menuType, std::stoi(input));
        }
        
        clear();
    }
}