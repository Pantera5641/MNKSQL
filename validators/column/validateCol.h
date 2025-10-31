#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>

#include "parser.h"
#include "path.h"
#include "symbols.h"
#include "messages.h"
#include "types.h"
#include "utilsTable.h"


struct ValidateCol
{
    private:
    bool checkParamErrors(const std::string& type, const std::string& param);

    bool checkSyntaxErrors(const std::string& argsString);

    public:
    std::string checkAddErrors(const std::string& argsString);

    std::string checkInsertErrors(const std::string& indexString, const std::string& argsString);

    std::string checkRemoveErrors(const std::string& indexString);
};