#include "startDrg.h"

extern std::string globalLanguage;


void startDrg()
{
    std::string input {};
    MenuType menuType {MenuType::Main};

    while (true) 
    {   
        std::cout << "\033[0;31m";
        show("MNKSQL_DRG/data/logo.txt");
        std::cout << "\033[0m" << std::endl;

        showMenu(menuType, globalLanguage);
        std::cin >> input;

        if (isDigit(input)) 
        {
            menuType = execute(menuType, std::stoi(input));
        }
        
        clear();
    }
}