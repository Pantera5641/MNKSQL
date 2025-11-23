#include "language.h"


std::string globalLanguage = "en";

MenuType executeLanguageMenu(int num)
{
    switch (num) 
    {
        case 1:
            globalLanguage = "en";
            return MenuType::Language;

        case 2:
            globalLanguage = "ru";
            return MenuType::Language;
        
        case 0:
            return MenuType::Main;

        default:
            return MenuType::Language;
    }
}