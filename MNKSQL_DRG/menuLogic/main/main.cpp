#include "main.h"


MenuType executeMainMenu(int num)
{
    switch (num) 
    {
        case 1:
            return User;

        case 2:
            return User;

        case 3:
            return Admin;

        case 4:
            return Admin;

        case 5:
            return Language;

        case 0:
            std::exit(0);
            break;

        default:
            return Main;
    }
}