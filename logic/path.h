#include <string>

#pragma once

class Path
{
    public:
    std::string construct(const std::string& fileName);

    std::string construct(const std::string& fileName, const std::string& extension);
};