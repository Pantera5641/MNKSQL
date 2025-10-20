#include "utilsCommandPwd.h"


void UtilsCommandPwd::setPassword(const std::string& fileName, const std::string& password)
{
    std::vector<std::string> data {UtilsTable().loadFile(fileName)};

    data.at(0) = LEFT_PARENTHESIS + password + RIGHT_PARENTHESIS;

    UtilsTable().saveFile(fileName, data);
}