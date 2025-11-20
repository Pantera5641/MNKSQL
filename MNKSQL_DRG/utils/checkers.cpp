#include "checkers.h"



bool isDigit(char ch)
{
    return std::isdigit(ch);
}

bool isDigit(const std::string& str)
{
    bool flag {true};
    for (int i = 0; i < str.size(); i++)
    {
        flag *= isDigit(str.at(i));
    }
    
    return flag;
}