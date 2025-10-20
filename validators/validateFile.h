#pragma once
#include <string>
#include <vector>
#include <filesystem>

#include "path.h"


struct ValidateFile
{
    public:
    bool isTableExists(const std::string& tableName);
};