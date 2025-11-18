#include "commandCol.h"


CommandCol::Commands CommandCol::strToAction(const std::string& str)
{ 
    if(str == "ADD") return Commands::Add;
    if(str == "INSERT") return Commands::Insert;
    if(str == "DELETE") return Commands::Delete;
    return Commands::Unknown;
}

void CommandCol::add(const std::string& argsString)
{
    std::string error {ValidateCol().checkAddErrors(argsString)};
    if (error != NONE) 
    {
        std::cout << error << std::endl;
        return;
    }

    DataStore& store = DataStore::getInstance();

    store.descriptor.fill(argsString);

    std::cout << COLUMN_ADDED_MESSAGE << std::endl;
}

void CommandCol::insert(const std::string& indexString, const std::string& argsString)
{
    std::string error {ValidateCol().checkInsertErrors(indexString, argsString)};
    if (error != NONE) 
    {
        std::cout << error << std::endl;
        return;
    }

    DataStore& store = DataStore::getInstance();
    int index {std::stoi(indexString) - 1};

    store.descriptor.insert(argsString, index);

    std::cout << COLUMN_INSERT_MESSAGE << std::endl;
}

void CommandCol::remove(const std::string& indexString)
{
    std::string error {ValidateCol().checkRemoveErrors(indexString)};
    if (error != NONE) 
    {
        std::cout << error << std::endl;
        return;
    }

    DataStore& store = DataStore::getInstance();

    store.descriptor.removeByIndex(std::stoi(indexString) - 1);
}

void CommandCol::execute(const std::vector<std::string>& items)
{
    Commands cmd = strToAction(items.at(1));

    switch (cmd)
    {
    case Commands::Add:
        try 
        {
            add(items.at(2));
        } 
        catch (...) 
        {
            std::cout << INVALID_ARGUMENTS_ERROR << std::endl;
        }
        break;

    case Commands::Insert:
        try 
        {
            insert(items.at(2), items.at(3));
        } 
        catch (...) 
        {
            std::cout << INVALID_ARGUMENTS_ERROR << std::endl;
        }
        break;

    case Commands::Delete:
        try 
        {
            remove(items.at(2));
        } 
        catch (...) 
        {
            std::cout << INVALID_ARGUMENTS_ERROR << std::endl;
        }
        break;

    case Commands::Unknown:
        std::cout << UNKNOWN_OPERATOR_ERROR << std::endl;
        break;
    }
}