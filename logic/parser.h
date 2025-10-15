#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

#include "helper.h"
#include "smartFile.h"

class Parser
{
    public:
    std::vector<std::string> DbIntoArray(const std::string& path);

    void ArrayIntoDB(const std::vector<std::string>& db, const std::string& path);

    std::vector<std::string> GetLine(const std::vector<std::string>& db, int num);

    std::vector<std::string> GetLine(const std::string& path, int num);

    std::vector<std::string> GetColumn(const std::vector<std::string>& db, int num);

    std::vector<std::string> GetColumn(const std::string& path, int num);

    std::string extractBetween(const std::string& line, char firstItem, char secondItem);

    std::string cutAfter(const std::string& line, char item);

    std::string cutBefore(const std::string& line, char item);
};
