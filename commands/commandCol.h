#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "database/dataStore.h"
#include "logic/helper.h"
#include "logic/path.h"
#include "logic/smartFile.h"


struct CommandCol
{
    private:
    enum Commands
    {
        Add,
        Edit,
        Delete,
        Unknown
    };

    Commands strToAction(std::string str);

    void add(const std::string& args);

    public:
    void execute(const std::vector<std::string>& items);
};