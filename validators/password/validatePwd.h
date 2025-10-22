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


struct ValidatePwd
{
    public:
    std::string checkSetErrors(const std::string& fileName, const std::string& newPassword);

    std::string checkEditErrors(const std::string& fileName, const std::string& oldPassword, const std::string& newPassword);
};