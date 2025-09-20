#include <string>

#include "path.h"

#pragma once

std::string Path::Construct(const std::string& fileName, const std::string& extension)
{
    const std::string path = "DataBases/";
    return path + fileName + extension;
}
