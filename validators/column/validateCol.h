#pragma once
#include <string>
#include <vector>
#include <filesystem>

#include "parser.h"
#include "path.h"
#include "symbols.h"
#include "types.h"
#include "utilsTable.h"


struct ValidateCol
{
    private:
    bool checkParamErrors(const std::string& param);

    bool checkSyntaxErrors(const std::string& argsString);

    public:
    std::string checkAddErrors(const std::string& argsString);
};