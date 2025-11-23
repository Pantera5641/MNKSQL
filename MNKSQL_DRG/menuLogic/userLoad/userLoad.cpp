#include "userLoad.h"


MenuType executeUserLoadMenu(int num)
{
    switch (num) 
    {
        case 1:
            return MenuType::UserLoad;

        case 2:
            return MenuType::UserLoad;

        case 0:
            return MenuType::User;

        default:
            return MenuType::UserLoad;
    }
}