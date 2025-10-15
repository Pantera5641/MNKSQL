#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "commandDb.h"
#include "command_row.cpp"
#include "commandCol.h"
#include "commandHelp.h"

#include "logic/helper.h"


struct CommandCore
{
    private: 
    enum Commands
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