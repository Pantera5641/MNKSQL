#include "user.h"


MenuType executeUserMenu(int num)
{
    switch (num) 
    {
        case 1:
            showEvent();
            return MenuType::User;

        case 2:
            return MenuType::UserLoad;

        case 3:
            sortEvent();
            return MenuType::User;

        case 0:
            return MenuType::Main;

        default:
            return MenuType::User;
    }
}