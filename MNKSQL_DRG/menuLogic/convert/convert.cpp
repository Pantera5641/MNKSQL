#include "convert.h"


MenuType executeConvertMenu(int num)
{
    switch (num) 
    {
        case 1:
            return MenuType::Convert;

        case 2:
            return MenuType::Convert;

        case 0:
            return MenuType::Admin;

        default:
            return MenuType::Convert;
    }
}