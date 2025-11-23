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