#pragma once
#include <string>
#include <vector>
#include <filesystem>

#include "parser.h"
#include "path.h"
#include "symbols.h"
#include "types.h"
#include "utilsTable.h"


struct ValidateFile
{
    public:
    bool isTableExists(const std::string& tableName);

    std::string checkSaveErrors(const std::string& fileName, const std::string& password);

    std::string checkLoadAndRemoveErrors(const std::string& fileName, const std::string& password);
};