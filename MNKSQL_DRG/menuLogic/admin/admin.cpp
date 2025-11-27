#include "admin.h"


MenuType executeAdminMenu(int num)
{
    switch (num) 
    {
        case 1:
            showEvent();
            return MenuType::Admin;

        case 2:
            return MenuType::AdminLoad;

        case 3:
            editEvent();
            return MenuType::Admin;
        
        case 4:
            removeEvent();
            return MenuType::Admin;
        
        case 5:
            addEvent();
            return MenuType::Admin;
        
        case 6:
            queryEvent();
            return MenuType::Admin;
        
        case 7:
            sortEvent();
            return MenuType::Admin;

        case 8:
            return MenuType::Convert;

        case 9:
            return MenuType::Save;

        case 0:
            return MenuType::Main;

        default:
            return MenuType::Admin;
    }
}