#include "main.h"


MenuType executeMainMenu(int num)
{
    switch (num) 
    {
        case 1:
            return MenuType::User;

        case 2:
            return MenuType::Admin;

        case 3:
            return MenuType::Admin;

        case 4:
            return MenuType::Language;

        case 0:
            std::exit(0);
            break;

        default:
            return MenuType::Main;
    }
}