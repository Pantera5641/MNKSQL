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

    std::cout << "Column added in database" << std::endl;
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
        std::cout << "Edit operation not implemented" << std::endl;
        break;

    case Commands::Delete:
        std::cout << "Delete operation not implemented" << std::endl;
        break;

    case Commands::Unknown:
        break;
    }
}