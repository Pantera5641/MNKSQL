#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "content/constants.h"
#include "database/dataStore.h"
#include "logic/parser.h"
#include "logic/helper.h"


struct CommandDb
{
    private:
    enum Commands
    {
        Show,
        Clean,
        Unknown
    };

    Commands strToAction(const std::string& str);

    void show();

    void clean();

    public:
    void execute(const std::vector<std::string>& arr);
};