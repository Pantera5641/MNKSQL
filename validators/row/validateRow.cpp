#include "validateRow.h"


std::string ValidateRow::checkAddErrors(const std::string& argsString)
{
    DataStore& store = DataStore::getInstance();

    int descriptorSize {store.descriptor.size()};
    if (store.descriptor.size() == 0)
    {
        return "ERROR: At least 1 column is needed to create a row.";
    }

    std::vector<std::string> args {Helper().strip(argsString, COMMA)};
    if (args.size() != descriptorSize)
    {
        return "ERROR: Invalid number of elements.";
    }

    return NONE;
}

std::string ValidateRow::checkRewriteErrors(const std::string& indexString, const std::string& argsString)
{
    if (Helper().isInt(indexString) == false) 
    {
        return "ERROR: Invalid number of row";
    }

    return NONE;
}

std::string ValidateRow::checkRemoveErrors(const std::string& indexString)
{
    if (Helper().isInt(indexString) == false) 
    {
        return "ERROR: Invalid number of row";
    }

    return NONE;
}