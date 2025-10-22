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

    for (std::string item : Helper().strip(argsString, COMMA))
    {
        if (item.find(EQUALS_SIGN) == std::string::npos) 
        {
            return INVALID_ARGUMENTS_ERROR;
        }
    }

    for (std::string nameOfField : store.descriptor.getFieldNames())
    {
        int count {};
        
        for (std::string item : Helper().strip(argsString, COMMA)) 
        {
            if (Parser().cutAfter(item, EQUALS_SIGN) != nameOfField) {count++;}
        }

        if (count == store.descriptor.size()) 
        {
            return ASSIGN_TO_NONEXISTENT_FIELD_ERROR;
        }
    }

    return NONE;
}

std::string ValidateRow::checkRewriteErrors(const std::string& indexString, const std::string& argsString)
{
    std::string errorIndex {checkRemoveErrors(argsString)};
    if (errorIndex != NONE) 
    {
        return errorIndex;
    }

    std::string errorArgs {checkAddErrors(argsString)};
    if (errorArgs != NONE) 
    {
        return errorArgs;
    }

    return NONE;
}

std::string ValidateRow::checkRemoveErrors(const std::string& indexString)
{
    DataStore& store = DataStore::getInstance();

    if (Helper().isInt(indexString) == false) 
    {
        return INVALID_ROW_NUMBER_ERROR;
    }

    if ( std::stoi(indexString) < 0 || std::stoi(indexString) > store.database.size()) 
    {
        return INVALID_ROW_NUMBER_ERROR;
    }

    return NONE;
}