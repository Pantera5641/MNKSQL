#include "language.h"


std::string globalLanguage = "en";

MenuType executeLanguageMenu(int num)
{
    switch (num) 
    {
        case 1:
            globalLanguage = "en";
            return Language;

        case 2:
            globalLanguage = "ru";
            return Language;
        
        case 0:
            return Main;

        default:
            return Language;
    }
}