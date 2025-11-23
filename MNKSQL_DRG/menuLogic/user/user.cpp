#include "user.h"


MenuType executeUserMenu(int num)
{
    switch (num) 
    {
        case 1:
            clear();
            showTable();
            await();
            return User;

        case 2:
            return User;

        case 3:
            return User;

        case 0:
            return Main;

        default:
            return User;
    }
}