#include <iostream>
#include <string>

#include "logic/helper.cpp"

class Command_Help
{
    public:
    void Show()
    {
        Helper().PrintTxt("content/help.txt");
    }
};