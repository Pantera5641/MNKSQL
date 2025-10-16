#pragma once
#include <string>


class Path
{
    public:
    std::string construct(const std::string& fileName);

    std::string construct(const std::string& fileName, const std::string& extension);
};