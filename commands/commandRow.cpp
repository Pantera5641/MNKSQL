#include "commandRow.h"


CommandRow::Commands CommandRow::strToAction(std::string str)
{
    if(str == "ADD") return Commands::Add; 
    if(str == "REWRITE") return Commands::Rewrite; 
    if(str == "REMOVE") return Commands::Remove; 
    return Commands::Unknown;
}

bool CommandRow::inDiapasone(int num, const std::string& argsString)
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

bool CommandRow::validator(const std::string& item, int index)
{
    DataStore& store = DataStore::getInstance();
    std::type_index type {store.descriptor.getFieldTypes()[index]};
    std::string param {store.descriptor.getFieldParams()[index]};

    if (typeid(item) == type) 
    {
        return true;
    }

    int intItem {};
    try 
    {
        intItem = std::stoi(item);
    } 
    catch(...)
    {
        return false;
    }

    if (param == NONE) 
    {
        return true;
    }

    if (inDiapasone(intItem ,param)) 
    {
        return true;
    }
    return false;
}

void CommandRow::add(const std::string& argsString)
{
    DataStore& store = DataStore::getInstance();
    int descriptorSize {store.descriptor.size()};

    std::vector<std::string> args {Helper().strip(argsString, COMMA)};
    std::vector<std::string> fields(descriptorSize);

    if (descriptorSize == 0)
    {
        std::cout << "Error: At least 1 column is needed to create a row." << std::endl;
        return;
    }

    if (args.size() != descriptorSize)
    {
        std::cout << "Error: Invalid number of elements." << std::endl;
        return;
    }

    for (std::string item : args)
    {
        std::string userNameOfField {Parser().cutAfter(item, EQUALS_SIGN)};
        std::string userField {Parser().cutBefore(item, EQUALS_SIGN)};

        for (int i = 0; i < descriptorSize; i++)
        {
            std::string nameOfField {store.descriptor.getFieldNames()[i]};

            if (userNameOfField == nameOfField)
            {
                if (validator(userField, i) != true) 
                {
                    std::cout << "Error in value:" << userNameOfField << std::endl;
                    return;
                }

                fields[i] = userField;
                break;
            }
        } 
    }

    store.addContainer(Helper().connect(fields, COMMA));

    std::cout << "Row added in database." << std::endl;
}

void CommandRow::rewrite(const std::string& indexString, const std::string& argsString)
{
    int index {};
    DataStore& store = DataStore::getInstance();

    try
    {
        index = std::stoi(indexString) - 1;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: Invalid number of row" << std::endl;
        return;
    }

    store.database[index] = store.descriptor.createContainer(argsString);

    std::cout << "Row was rewrite" << std::endl;
}

void CommandRow::remove(const std::string& indexString)
{
    int index {};
    DataStore& store = DataStore::getInstance();

    try
    {
        index = std::stoi(indexString) - 1;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: Invalid number of row" << std::endl;
        return;
    }

    store.database.erase(store.database.begin() + index);

    std::cout << "Row was deleted" << std::endl;
}

void CommandRow::execute(const std::vector<std::string>& items)
{
    Commands cmd = strToAction(items[1]);

    switch (cmd)
    {
    case Commands::Add:
        add(items[2]);
        break;
    case Commands::Rewrite:
        rewrite(items[2], items[3]);
        break;
    case Commands::Remove:
        remove(items[2]);
        break;
    case Commands::Unknown:
        std::cout << "Error: Unknown operation" << std::endl;
        break;
    }
}