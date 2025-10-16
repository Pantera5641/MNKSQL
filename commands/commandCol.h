#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "../database/dataStore.h"


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

    Commands strToAction(const std::string& str);

    void add(const std::string& args);

    public:
    void execute(const std::vector<std::string>& items);
};