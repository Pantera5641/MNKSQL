#include "commandCore.h"


CommandCore::Commands CommandCore::StrToCommand(const std::string& str)
{
    if (str == "PWD") return Commands::Password;
    if (str == "FILE") return Commands::File;
    if (str == "DB") return Commands::Database;
    if (str == "VIEW") return Commands::View;
    if (str == "COL") return Commands::Column;
    if (str == "ROW") return Commands::Row;
    if (str == "HELP") return Commands::Help;
    if (str == "SAVE") return Commands::Save;
    if (str == "LOAD") return Commands::Load;
    if (str == "EXIT") return Commands::Exit;
    return Commands::Unknown;
}

void CommandCore::commandHandler(const std::string& userInput)
{
    std::vector<std::string> items = Helper().strip(userInput, SPACE);

    Commands cmd = StrToCommand(items.front());

    switch (cmd)
    {
    case Commands::Password:
        CommandPwd().execute(items);
        break;
    
    case Commands::File:
        CommandFile().execute(items);
        break;

    case Commands::Database:
        CommandDb().execute(items);
        break;
    
    case Commands::View:
        CommandView().execute(items);
        break;
    
    case Commands::Column:
        CommandCol().execute(items);
        break;

    case Commands::Row:
        CommandRow().execute(items);
        break;

    case Commands::Help:
        CommandHelp().show();
        break;
    
    case Commands::Save:
        std::cout << "Command not implemented" << std::endl;
        break;
    
    case Commands::Load:
        std::cout << "Command not implemented" << std::endl;
        break;
    
    case Commands::Exit:
        std::cout << "Command not implemented" << std::endl;
        break;

    case Commands::Unknown:
        std::cout << "Error: Unknown command" << std::endl;
        break;
    }
}