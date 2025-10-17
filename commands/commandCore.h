#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "commandDb.h"
#include "commandRow.h"
#include "commandCol.h"
#include "commandFile.h"
#include "commandHelp.h"

#include "symbols.h"
#include "helper.h"


struct CommandCore
{
    private: 
    enum Commands
    {
        Password,
        File,
        Database,
        View,
        Row,
        Column,
        Help,
        Save,
        Load,
        Exit,
        Unknown
    };

    Commands StrToCommand(const std::string& str);

    public:
    void commandHandler(const std::string& str);
};