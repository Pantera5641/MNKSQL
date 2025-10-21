#pragma once
#include <iostream>
#include <vector>
#include <filesystem>

#include "utilsTable.h" 
#include "validateFile.h"

#include "dataStore.h"
#include "path.h"


struct CommandFile
{
    private:
    enum Commands
    {
        Save,
        Load,
        Remove,
        Unknown
    };

    Commands strToAction(const std::string& str);

    void save(const std::string& fileName, const std::string& password = NONE);

    void load(const std::string& fileName, const std::string& password = NONE);

    void remove(const std::string& fileName, const std::string& password = NONE);

    public:
    void execute(const std::vector<std::string>& items);
};