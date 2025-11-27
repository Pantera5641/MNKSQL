#include "startDrg.h"


void startDrg()
{
    std::string input {};
    MenuType menuType {MenuType::Main};

    while (true) 
    {   
        show(LOGO_PATH_DRG, "\033[0;31m");

        showMenu(menuType);
        std::cin >> input;

        if (isDigit(input)) 
        {
            menuType = execute(menuType, std::stoi(input));
        }
        
        clear();
    }
}