#include <string>
#include <vector>
#include <sstream>

#include "smartFile.h"

#pragma once

class Helper
{
    public:
    std::vector<std::string> strip(const std::string& str, char toRemove);

    std::string connect(const std::vector<std::string>& vec, char arg);

    std::string repeat(int num, char item);

    void printTxt(const std::string& path);

    bool isInt(const std::string& item);
};