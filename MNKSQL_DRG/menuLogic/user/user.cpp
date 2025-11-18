#include "user.h"


MenuType executeUserMenu(int num)
{
    switch (num) 
    {
        case 1:
            return User;
            break;

        case 2:
            return User;
            break;

        case 3:
            return User;
            break;

        case 0:
            return Main;
            break;

        default:
            return User;
    }
}