#include "checkers.h"


bool isDigit(char ch)
{
    return std::iswdigit(ch);
}

bool isDigit(const std::string& str)
{
    bool flag {true};
    for (int i = 0; i < str.size(); i++)
    {
        flag *= isDigit(str.at(i));
        if (flag == false) return flag;
    }
    
    return flag;
}

bool isContainDigits(const std::string& str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (isDigit(str.at(i)) == true)
        {
            return false;
        }
    }
    return true;
}

bool isContainSpecialSigns(const std::string& str)
{
    std::string signs {".,<>/?|;:"};

    for (int i = 0; i < signs.size(); i++) 
    {
        for (int j = 0; j < str.size(); j++)
        {
            if (signs.at(i) == str.at(j)) return false;
        }
    }

    return true;
}

bool inRange(int num, int leftBorder, int rightBorder)
{
    return leftBorder <= num && num < rightBorder;
}

bool inRange(const std::string& numStr, int leftBorder, int rightBorder)
{
    if (isDigit(numStr) == false) return false;

    return inRange(std::stoi(numStr), leftBorder, rightBorder);
}