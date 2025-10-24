#include "commandRow.h"


CommandRow::Commands CommandRow::strToAction(std::string str)
{
    if(str == "ADD") return Commands::Add; 
    if(str == "EDIT") return Commands::Rewrite; 
    if(str == "DELETE") return Commands::Remove; 
    return Commands::Unknown;
}

void CommandRow::add(const std::string& argsString)
{
    std::string error {ValidateRow().checkAddErrors(argsString)};
    if (error != NONE) 
    {
        std::cout << error << std::endl;
        return;
    }

    DataStore& store = DataStore::getInstance();
    std::string fields = UtilsCommandRow().prepareArgs(argsString);

    store.addContainer(fields);

    std::cout << ROW_ADDED_MESSAGE << std::endl;
}

void CommandRow::edit(const std::string& indexString, const std::string& argsString)
{
    std::string error {ValidateRow().checkEditErrors(indexString, argsString)};
    if (error != NONE) 
    {
        std::cout << error << std::endl;
        return;
    }

    int index {std::stoi(indexString) - 1};
    DataStore& store = DataStore::getInstance();
    std::vector<std::string> fields = Helper().strip(UtilsCommandRow().prepareArgs(argsString), COMMA);

    for (int i = 0; i < store.descriptor.size(); i++) 
    {
        if (fields.at(i) == NONE) 
        {
            fields.at(i) = store.database.at(index).getItem(i);
        }
    }

    store.database[index] = store.descriptor.createContainer(Helper().connect(fields, COMMA));

    std::cout << ROW_EDITED_MESSAGE << std::endl;
}

void CommandRow::remove(const std::string& indexString)
{
    std::string error {ValidateRow().checkRemoveErrors(indexString)};
    if (error != NONE) 
    {
        std::cout << error << std::endl;
        return;
    }

    int index {std::stoi(indexString) - 1};
    DataStore& store = DataStore::getInstance();

    store.database.erase(store.database.begin() + index);

    std::cout << ROW_DELETED_MESSAGE << std::endl;
}

void CommandRow::execute(const std::vector<std::string>& items)
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

    case Commands::Rewrite:
        try 
        {
            edit(items.at(2), items.at(3));
        } 
        catch (...) 
        {
            std::cout << INVALID_ARGUMENTS_ERROR << std::endl;
        }
    
        break;

    case Commands::Remove:
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