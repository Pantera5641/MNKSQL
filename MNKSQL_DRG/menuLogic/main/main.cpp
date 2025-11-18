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
            return Main;

        case 4:
            return Main;

        case 5:
            return Language;

        case 0:
            std::exit(0);
            break;

        default:
            return Unknown;
    }
}