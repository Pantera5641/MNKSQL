#pragma once
#include <iostream>
#include <vector>
#include <filesystem>

#include "dataStore.h"
#include "path.h"


struct CommandFile
{
    private:
    enum Commands
    {
        Save,
        Load,
        Unknown
    };

    Commands strToAction(const std::string& str);

    void saveTxt(const std::string& fileName, const std::vector<std::string>& data);

    void saveBin(const std::string& fileName, const std::vector<std::string>& data);

    void save(const std::string& fileName, const std::string& password = std::string());

    void load(const std::string& fileName, const std::string& password = std::string());

    void remove(const std::string& fileName, const std::string& password = std::string());

    public:
    void execute(const std::vector<std::string>& items);
};