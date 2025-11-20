#include "admin.h"


MenuType executeAdminMenu(int num)
{
    switch (num) 
    {
        case 1:
            return MenuType::Admin;

        case 2:
            return MenuType::Admin;

        case 3:
            return MenuType::Admin;
        
        case 4:
            return MenuType::Admin;
        
        case 5:
            return MenuType::Admin;
        
        case 6:
            return MenuType::Admin;
        
        case 7:
            return MenuType::Admin;

        case 8:
            return MenuType::Admin;

        case 9:
            return MenuType::Admin;

        case 0:
            return MenuType::Main;

        default:
            return MenuType::Admin;
    }
}