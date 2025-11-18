#include "utilsCommandRow.h"


bool UtilsCommandRow::inStringDigits(const std::string& str)
{
    for (char item : str)
    {
        if (Helper().isInt({item}) == true)
        {
            return false;
        }
    }
    return true;
}

bool UtilsCommandRow::inRange(int num, const std::string& argsString)
{
    if (argsString.find(GREATER_THAN) && std::count(argsString.begin(), argsString.end(), GREATER_THAN) == 1) 
    {
        std::vector<std::string> args = Helper().strip(argsString, GREATER_THAN);
        if (args[0] == "X" && Helper().isInt(args[1])) 
        {
            return num > std::stoi(args[1]);
        }
    }

    if (argsString.find(LESS_THAN) && std::count(argsString.begin(), argsString.end(), LESS_THAN) == 1) 
    {
        std::vector<std::string> args = Helper().strip(argsString, LESS_THAN);
        if (args[0] == "X" && Helper().isInt(args[1])) 
        {
            return num < std::stoi(args[1]);
        }
    }

    if (argsString.find(LESS_THAN) && std::count(argsString.begin(), argsString.end(), LESS_THAN) == 2) 
    {
        std::vector<std::string> args = Helper().strip(argsString, LESS_THAN);
        if (Helper().isInt(args[0]) && args[1] == "X" && Helper().isInt(args[2])) 
        {
            return std::stoi(args[0]) < num && num < std::stoi(args[2]);
        }
    }
    return false;
}

bool UtilsCommandRow::validator(const std::string& item, int index)
{
    DataStore& store = DataStore::getInstance();
    std::type_index type {store.descriptor.getFieldTypes()[index]};
    std::string param {store.descriptor.getFieldParams()[index]};

    if (type == STRING_TYPE && inStringDigits(item))
    {
        return true;
    }

    if (Helper().isInt(item) == true && type == INT_TYPE && inRange(std::stoi(item) ,param)) 
    {
        return true;
    }

    return false;
}

std::string UtilsCommandRow::prepareArgs(const std::string& argsString)
{
    DataStore& store = DataStore::getInstance();
    int descriptorSize {store.descriptor.size()};

    std::vector<std::string> args {Helper().strip(argsString, COMMA)};
    std::vector<std::string> fields(descriptorSize);

    for (std::string item : args)
    {
        std::string userNameOfField {Parser().cutAfter(item, EQUALS_SIGN)};
        std::string userField {Parser().cutBefore(item, EQUALS_SIGN)};

        for (int i = 0; i < descriptorSize; i++)
        {
            std::string nameOfField {store.descriptor.getFieldNames()[i]};

            if (userNameOfField == nameOfField)
            {
                fields[i] = userField;
                break;
            }
        } 
    }

    for (int i = 0; i < descriptorSize; i++) 
    {
        if (fields.at(i) == std::string()) 
        {
            fields.at(i) = NONE;
        }
    }

    return Helper().connect(fields, COMMA);
}