#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "commandDb.h"
#include "command_row.cpp"
#include "command_col.cpp"
#include "commandHelp.h"

#include "logic/helper.h"


struct CommandCore
{
    private: 
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

    Commands StrToCommand(std::string str);

    public:
    void commandHandler(std::string str);
};