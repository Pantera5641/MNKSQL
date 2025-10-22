#include "commandDb.h"


CommandDb::Commands CommandDb::strToAction(const std::string& str)
{
    if(str == "SHOW") return Commands::Show;
    if(str == "CLEAN") return Commands::Clean; 
    return Commands::Unknown;
}

void CommandDb::show()
{
    std::string error {ValidateDb().checkShowErrors()};
    if (error != NONE) 
    {
        std::cout << error << std::endl;
        return;
    }

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

    std::cout << CONFIRM_DATABASE_DELETE_PROMPT << std::endl;
    std::cin >> userInput;

    if (userInput == "Y")
    {
        store.database.clear();
        store.descriptor.clear();
        std::cout << DATABASE_CLEARED_MESSAGE << std::endl;
    }
    else if (userInput == "N")
    {
        return;
    }
    else
    {
        std::cout << SYNTAX_ERROR << std::endl;
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
        std::cout << UNKNOWN_OPERATOR_ERROR << std::endl;
        break;
    }
}