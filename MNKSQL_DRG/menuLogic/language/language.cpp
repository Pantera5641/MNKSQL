#include "language.h"


std::string globalLanguage = "en";

MenuType executeLanguageMenu(int num)
{
    switch (num) 
    {
        case 1:
            globalLanguage = "en";
            break;

        case 2:
            globalLanguage = "ru";
            break;

        default:
            return Unknown;
    }

    return Main;
}