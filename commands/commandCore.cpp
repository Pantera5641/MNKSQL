#include "commandCore.h"


CommandCore::Commands CommandCore::StrToCommand(std::string str)
{
    if (str == "DB") return Commands::Db;
    if (str == "ROW") return Commands::Row;
    if (str == "COL") return Commands::Col;
    if (str == "SORT") return Commands::Sort;
    if (str == "DATA") return Commands::Data;
    if (str == "HELP") return Commands::Help;
    return Commands::Unknown;
}

void CommandCore::commandHandler(std::string str)
{
    std::vector<std::string> items = Helper().strip(str, ' ');

    Commands cmd = StrToCommand(items.front());

    switch (cmd)
    {
    case Commands::Db:
        CommandDb().execute(items);
        break;
    
    case Commands::Row:
        if(globalDbName == "") std::cout << "Error: Select the database you will work with." << std::endl;
        Command_Row().Execute(items);
        break;

    case Commands::Col:
        if(globalDbName == "") std::cout << "Error: Select the database you will work with." << std::endl;
        Command_Col().Execute(items);
        break;
    
    case Commands::Sort:
        std::cout << "Sort command not implemented" << std::endl;
        break;
    
    case Commands::Data:
        std::cout << "Data command not implemented" << std::endl;
        break;

    case Commands::Help:
        CommandHelp().Show();
        break;

    case Commands::Unknown:
        std::cout << "Error: Unknown command" << std::endl;
        break;
    }
}