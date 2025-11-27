#include "save.h"


MenuType executeSaveMenu(int num)
{
    switch (num) 
    {
        case 1:
            saveTxtEvent();
            return MenuType::Save;

        case 2:
            return MenuType::Save;

        case 0:
            return MenuType::Admin;

        default:
            return MenuType::Save;
    }
}