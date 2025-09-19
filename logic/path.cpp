#include <iostream>
#include <string>

#pragma once

extern std::string globalDbName;

class Path
{
    public:
    std::string Construct(std::string extension)
    {
        const std::string path = "DataBases/";
        return path + globalDbName + extension;
    }
}