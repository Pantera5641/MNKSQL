#include <iostream>
#include <string>

#include "logic/helper.h"

class Command_Help
{
    public:
    void Show()
    {
        Helper().PrintTxt("content/help.txt");
    }
};