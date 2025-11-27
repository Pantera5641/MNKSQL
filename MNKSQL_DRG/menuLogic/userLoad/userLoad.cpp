#include "userLoad.h"


MenuType executeUserLoadMenu(int num)
{
    switch (num) 
    {
        case 1:
            loadTxtEvent();
            return MenuType::UserLoad;

        case 2:
            loadBinEvent();
            return MenuType::UserLoad;

        case 0:
            return MenuType::User;

        default:
            return MenuType::UserLoad;
    }
}