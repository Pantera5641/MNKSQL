#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>


#pragma once

struct Helper
{
    public:
    std::vector<std::string> strip(const std::string& str, char toRemove);

    std::string connect(const std::vector<std::string>& vec, char arg);

    std::string repeat(int num, char item);

    void printTxt(const std::string& path);

    bool isInt(const std::string& item);
};