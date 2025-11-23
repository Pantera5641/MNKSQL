#include "language.h"


MenuType executeLanguageMenu(int num)
{
    switch (num) 
    {
        case 1:
            setLanguage("en");
            return MenuType::Language;

        case 2:
            setLanguage("ru");
            return MenuType::Language;
        
        case 0:
            return MenuType::Main;

        default:
            return MenuType::Language;
    }
}