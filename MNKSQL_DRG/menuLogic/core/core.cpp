#include "core.h"


MenuType execute(MenuType menuType, int num)
{
    switch (menuType)
    {
        case MenuType::Main:
            return executeMainMenu(num);
        
        case MenuType::Language:
            return executeLanguageMenu(num);
        
        case MenuType::User:
            return executeUserMenu(num);

        case MenuType::Admin:
            return executeAdminMenu(num);

        default:
            return Main;
    }
}