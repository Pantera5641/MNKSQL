#pragma once
#include <string>
#include <vector>
#include <filesystem>

#include "parser.h"
#include "path.h"
#include "types.h"
#include "symbols.h"
#include "messages.h"
#include "utilsTable.h"


struct ValidateFile
{
    private:
    bool isTableExists(const std::string& tableName);

    public:
    std::string checkSaveErrors(const std::string& fileName, const std::string& password);

    std::string checkLoadAndRemoveErrors(const std::string& fileName, const std::string& password);
};