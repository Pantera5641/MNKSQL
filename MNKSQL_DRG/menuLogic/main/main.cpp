#include "main.h"


MenuType executeMainMenu(int num)
{
    switch (num) 
    {
        case 1:
            return Main;
            break;

        case 2:
            return Main;
            break;

        case 3:
            return Main;
            break;

        case 4:
            return Main;
            break;

        case 5:
            return Language;
            break;

        case 0:
            std::exit(0);
            break;

        default:
            return Unknown;
    }
}