#include "main.h"


MenuType executeMainMenu(int num)
{
    switch (num) 
    {
        case 1:
            return MenuType::User;

        case 2:
            return loginEvent();

        case 3:
            registrationEvent();
            return MenuType::Main;

        case 4:
            return MenuType::Language;

        case 0:
            std::exit(0);
            break;

        default:
            return MenuType::Main;
    }
}