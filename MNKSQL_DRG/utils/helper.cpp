#include "helper.h"


std::string repeat(int num, char item)
{
    std::string result {};

    for (int i = 0; i < num; i++)
    {
        result+= item;
    }
    
    return result;
}

std::string cutAfter(const std::string& line, char item)
{
    int index = line.find_first_of(item);
    std::string result = line.substr(0, index);

    return result;
}

std::string cutBefore(const std::string& line, char item)
{
    int index = line.find_first_of(item);
    std::string result = line.substr(index + 1);

    return result;
}