#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "validateRow.h"
#include "utilsCommandRow.h"

#include "dataStore.h"
#include "helper.h"
#include "symbols.h"
#include "messages.h"


struct CommandRow
{
    private:
    enum class Commands
    {
        Add,
        Rewrite,
        Remove,
        Unknown
    };

    Commands strToAction(std::string str);

    void add(const std::string& argsString);

    void rewrite(const std::string& indexString, const std::string& argsString);

    void remove(const std::string& indexString);

    public:
    void execute(const std::vector<std::string>& items);
};