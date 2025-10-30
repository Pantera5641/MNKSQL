#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "symbols.h"
#include "messages.h"
#include "dataStore.h"
#include "helper.h"

#include "utilsShow.h"
#include "validateDb.h"


struct CommandDb
{
    private:
    enum Commands
    {
        Show,
        Clean,
        TempSort,
        Unknown
    };

    Commands strToAction(const std::string& str);

    void show();

    void clean();

    //temp
    void bubbleSort(int index);

    //temp
    void tempSort(const std::string& fieldsString);

    public:
    void execute(const std::vector<std::string>& items);
};