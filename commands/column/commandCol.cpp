#include "commandCol.h"


CommandCol::Commands CommandCol::strToAction(const std::string& str)
{ 
    if(str == "ADD") return Commands::Add;
    if(str == "EDIT") return Commands::Edit;
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
        
        }
        break;

    case Commands::Edit:
        std::cout << OPERATION_NOT_IMPLEMENTED_ERROR << std::endl;
        break;

    case Commands::Delete:
        std::cout << OPERATION_NOT_IMPLEMENTED_ERROR << std::endl;
        break;

    case Commands::Unknown:
        std::cout << UNKNOWN_OPERATOR_ERROR << std::endl;
        break;
    }
}