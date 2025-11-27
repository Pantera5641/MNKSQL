#include "adminLoad.h"


MenuType executeAdminLoadMenu(int num)
{
    switch (num) 
    {
        case 1:
            loadTxtEvent();
            return MenuType::AdminLoad;

        case 2:
            loadBinEvent();
            return MenuType::AdminLoad;
        
        case 3:
            loadKeyboardEvent();
            return MenuType::AdminLoad;

        case 0:
            return MenuType::Admin;

        default:
            return MenuType::AdminLoad;
    }
}