#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "messages.h"
#include "dataStore.h"
#include "validateCol.h"


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

    void add(const std::string& argsString);

    void edit(const std::string& indexString, const std::string& argsString);

    void remove(const std::string& indexString);

    public:
    void execute(const std::vector<std::string>& items);
};