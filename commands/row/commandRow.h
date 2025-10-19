#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "utilsCommandRow.h"

#include "dataStore.h"
#include "helper.h"
#include "symbols.h"


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

    bool inDiapasone(int num, const std::string& argsString);

    bool validator(const std::string& rowElement, int index);

    void add(const std::string& argsString);

    void rewrite(const std::string& indexString, const std::string& argsString);

    void remove(const std::string& indexString);

    public:
    void execute(const std::vector<std::string>& items);
};