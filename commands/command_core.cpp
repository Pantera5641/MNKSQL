#include <iostream>
#include <string>
#include <vector>

#include "command_db.cpp"
#include "command_row.cpp"
#include "command_col.cpp"
#include "command_help.cpp"

#include "logic/helper.h"

enum class Commands
{
    Db,
    Row,
    Col,
    Sort,
    Data,
    Help,
    Unknown
};
class Command_Core
{
    private: 
    Commands StrToCommand(std::string str)
    {
        if (str == "DB") return Commands::Db;
        if (str == "ROW") return Commands::Row;
        if (str == "COL") return Commands::Col;
        if (str == "SORT") return Commands::Sort;
        if (str == "DATA") return Commands::Data;
        if (str == "HELP") return Commands::Help;
        return Commands::Unknown;
    }

    public:
    void commandHandler(std::string str)
    {
        std::vector<std::string> items = Helper().Strip(str, ' ');

        Commands cmd = StrToCommand(items.front());

        switch (cmd)
        {
        case Commands::Db:
            Command_Db().Execute(items);
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
            Command_Help().Show();
            break;

        case Commands::Unknown:
            std::cout << "Error: Unknown command" << std::endl;
            break;
        }
    }
};