#include "commandDb.h"


CommandDb::Commands CommandDb::strToAction(const std::string& str)
{
    if(str == "SHOW") return Commands::Show;
    if(str == "CLEAN") return Commands::Clean; 
    return Commands::Unknown;
}

void CommandDb::show()
{
    DataStore& store = DataStore::getInstance();
    std::vector<std::string> db {Helper().connect(store.descriptor.getFieldNames(), COMMA)};

    for (Container item : store.database) 
    {
        db.push_back(Helper().connect(item.getFields(), COMMA));
    } 

    
    UtilsShow().showTable(db);
}

void CommandDb::clean()
{
    DataStore& store = DataStore::getInstance();
    std::string userInput {};

    std::cout << "This will delete all data from the database. Are you sure?(Y/N)" << std::endl;
    std::cin >> userInput;

    if (userInput == "Y")
    {
        store.database.clear();
        store.descriptor.clear();
        std::cout << "Database cleared." << std::endl;
    }
    else if (userInput == "N")
    {
        return;
    }
    else
    {
        std::cout << "Syntax error." << std::endl;
        return;
    }
}

void CommandDb::execute(const std::vector<std::string>& items)
{
    Commands cmd = strToAction(items.at(1));

    switch (cmd)
    {
    case Commands::Show:
        show();
        break;

    case Commands::Clean:
        clean();
        break;

    case Commands::Unknown:
        std::cout << "ERROR: Unknown operator" << std::endl;
        break;
    }
}