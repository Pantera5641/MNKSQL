#include "path.h"

#pragma once

std::string Path::construct(const std::string& fileName)
{
    const std::string path = "tables/";
    return path + fileName;
}

std::string Path::construct(const std::string& fileName, const std::string& extension)
{
    return construct(fileName) + extension;
}
