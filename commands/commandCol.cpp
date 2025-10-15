#include "commandCol.h"


CommandCol::Commands CommandCol::strToAction(std::string str)
{ 
    if(str == "ADD") return Commands::Add;
    if(str == "EDIT") return Commands::Edit;
    if(str == "DELETE") return Commands::Delete;
    return Commands::Unknown;
}

void CommandCol::add(const std::string& args)
{
    DataStore& store = DataStore::getInstance();

    store.descriptor.fill(args);

    std::cout << "Column added in database" << std::endl;
}

void CommandCol::execute(const std::vector<std::string>& items)
{
    Commands cmd = strToAction(items[1]);

    switch (cmd)
    {
    case Commands::Add:
        add(items[2]);
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