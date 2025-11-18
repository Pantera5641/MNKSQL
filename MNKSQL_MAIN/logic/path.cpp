#include "path.h"


std::string Path::construct(const std::string& fileName)
{
    const std::string path = "MNKSQL_MAIN/tables/";
    return path + fileName;
}

std::string Path::construct(const std::string& fileName, const std::string& extension)
{
    return construct(fileName) + extension;
}
