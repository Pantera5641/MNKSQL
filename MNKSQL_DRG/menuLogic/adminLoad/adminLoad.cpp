#include "adminLoad.h"


MenuType executeAdminLoadMenu(int num)
{
    switch (num) 
    {
        case 1:
            return MenuType::AdminLoad;

        case 2:
            return MenuType::AdminLoad;
        
        case 3:
            addEvent();
            return MenuType::AdminLoad;

        case 0:
            return MenuType::Admin;

        default:
            return MenuType::AdminLoad;
    }
}