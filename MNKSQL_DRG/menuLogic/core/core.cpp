#include "core.h"
#include "userLoad.h"


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
        
        case MenuType::UserLoad:
            return executeUserLoadMenu(num);

        case MenuType::Admin:
            return executeAdminMenu(num);
        
        case MenuType::AdminLoad:
            return executeAdminLoadMenu(num);

        default:
            return Main;
    }
}