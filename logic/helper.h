#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#pragma once

class Helper
{
    public:
    std::vector<std::string> Strip(const std::string& str, char toRemove);

    std::string Connect(const std::vector<std::string>& vec, char arg);

    std::string Repeat(int num, char item);

    void PrintTxt(const std::string& path);
};