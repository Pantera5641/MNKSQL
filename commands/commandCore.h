#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "commandDb.h"
#include "commandRow.h"
#include "commandCol.h"
#include "commandFile.h"
#include "commandHelp.h"

#include "content/constants.h"
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
        File,
        Help,
        Unknown
    };

    Commands StrToCommand(const std::string& str);

    public:
    void commandHandler(const std::string& str);
};