#include "validatePwd.h"


std::string ValidatePwd::checkSetErrors(const std::string& fileName, const std::string& newPassword)
{
    std::string password {UtilsTable().loadFile(fileName).at(0)};
    if (password != (LEFT_PARENTHESIS + NONE + RIGHT_PARENTHESIS))
    {
        return FILE_ALREADY_HAS_PASSWORD_ERROR;
    }

    return NONE;
}

std::string ValidatePwd::checkEditErrors(const std::string& fileName, const std::string& oldPassword, const std::string& newPassword)
{
    std::string password {UtilsTable().loadFile(fileName).at(0)};
    if (password != (LEFT_PARENTHESIS + oldPassword + RIGHT_PARENTHESIS))
    {
        return INCORRECT_PASSWORD_ERROR;
    }

    return NONE;
}