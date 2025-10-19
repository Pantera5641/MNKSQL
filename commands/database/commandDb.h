#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "symbols.h"
#include "dataStore.h"
#include "helper.h"


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
    void execute(const std::vector<std::string>& items);
};