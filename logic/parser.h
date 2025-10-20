#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "helper.h"


struct Parser
{
    public:
    void arrayIntoDB(const std::vector<std::string>& db, const std::string& path);

    std::vector<std::string> getLine(const std::vector<std::string>& db, int num);

    std::vector<std::string> getColumn(const std::vector<std::string>& db, int num);

    std::string extractBetween(const std::string& line, char firstItem, char secondItem);

    std::string cutAfter(const std::string& line, char item);

    std::string cutBefore(const std::string& line, char item);
};
