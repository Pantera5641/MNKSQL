#include <iostream>
#include <string>

#include "content/globals.h"

#pragma once


class Path
{
    public:
    std::string Construct(std::string extension)
    {
        const std::string path = "DataBases/";
        return path + globalDbName + extension;
    }
};