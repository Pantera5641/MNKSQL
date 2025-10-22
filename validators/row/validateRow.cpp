#include "validateRow.h"


std::string ValidateRow::checkAddErrors(const std::string& argsString)
{
    DataStore& store = DataStore::getInstance();

    int descriptorSize {store.descriptor.size()};
    if (store.descriptor.size() == 0)
    {
        return INSUFFICIENT_COLUMNS_ERROR;
    }

    std::vector<std::string> args {Helper().strip(argsString, COMMA)};
    if (args.size() != descriptorSize)
    {
        return INVALID_ARGUMENTS_ERROR;
    }

    return NONE;
}

std::string ValidateRow::checkRewriteErrors(const std::string& indexString, const std::string& argsString)
{
    if (Helper().isInt(indexString) == false) 
    {
        return INVALID_ROW_NUMBER_ERROR;
    }

    return NONE;
}

std::string ValidateRow::checkRemoveErrors(const std::string& indexString)
{
    if (Helper().isInt(indexString) == false) 
    {
        return INVALID_ROW_NUMBER_ERROR;
    }

    return NONE;
}