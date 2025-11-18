#include "core.h"


MenuType execute(MenuType menuType, int num)
{
    switch (menuType)
    {
        case MenuType::Main:
            return executeMainMenu(num);
            break;
        
        case MenuType::Language:
            return executeLanguageMenu(num);
            break;

        default:
            std::cout << "unknown" << std::endl;
            return Unknown;
            break;
    }
}