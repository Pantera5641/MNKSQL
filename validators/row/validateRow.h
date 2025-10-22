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


struct ValidateRow
{
    public:
    std::string checkAddErrors(const std::string& argsString);

    std::string checkRewriteErrors(const std::string& indexString, const std::string& argsString);

    std::string checkRemoveErrors(const std::string& indexString);
};