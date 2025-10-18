#pragma once
#include <vector>
#include <filesystem>

#include "dataStore.h"
#include "path.h"


struct UtilsFile
{
    public:
    void saveTxt(const std::string& fileName, const std::vector<std::string>& data);

    void saveBin(const std::string& fileName, const std::vector<std::string>& data);

    std::vector<std::string> loadTxt(const std::string& fileName);

    std::vector<std::string> loadBin(const std::string& fileName);
};