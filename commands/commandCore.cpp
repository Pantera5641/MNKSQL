#include "commandCore.h"


CommandCore::Commands CommandCore::StrToCommand(std::string str)
{
    if (str == "DB") return Commands::Db;
    if (str == "COL") return Commands::Col;
    if (str == "ROW") return Commands::Row;
    if (str == "SORT") return Commands::Sort;
    if (str == "DATA") return Commands::Data;
    if (str == "FILE") return Commands::File;
    if (str == "HELP") return Commands::Help;
    return Commands::Unknown;
}

void CommandCore::commandHandler(std::string userInput)
{
    std::vector<std::string> items = Helper().strip(userInput, SPACE);

    Commands cmd = StrToCommand(items.front());

    switch (cmd)
    {
    case Commands::Db:
        CommandDb().execute(items);
        break;
    
    case Commands::Col:
        CommandCol().execute(items);
        break;

    case Commands::Row:
        CommandRow().execute(items);
        break;
    
    case Commands::Sort:
        std::cout << "Sort command not implemented" << std::endl;
        break;
    
    case Commands::Data:
        std::cout << "Data command not implemented" << std::endl;
        break;

    case Commands::File:
        CommandFile().execute(items);
        break;

    case Commands::Help:
        CommandHelp().show();
        break;

    case Commands::Unknown:
        std::cout << "Error: Unknown command" << std::endl;
        break;
    }
}