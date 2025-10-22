#include "validatePwd.h"


std::string ValidatePwd::checkSetErrors(const std::string& fileName, const std::string& newPassword)
{
    std::string password {UtilsTable().loadFile(fileName).at(0)};
    if (password != (LEFT_PARENTHESIS + NONE + RIGHT_PARENTHESIS))
    {
        return "ERROR: This file already has a password, use the EDIT command to change it";
    }

    return NONE;
}

std::string ValidatePwd::checkEditErrors(const std::string& fileName, const std::string& oldPassword, const std::string& newPassword)
{
    std::string password {UtilsTable().loadFile(fileName).at(0)};
    if (password != (LEFT_PARENTHESIS + oldPassword + RIGHT_PARENTHESIS))
    {
        return "ERROR: Incorrect password";
    }

    return NONE;
}