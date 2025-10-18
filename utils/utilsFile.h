#pragma once
#include <vector>
#include <fstream>
#include <filesystem>

#include "path.h"
#include "symbols.h"
#include "dataStore.h"


struct UtilsFile
{
    public:
    void saveRawData(const std::string& fileName, const std::string& password);

    void saveRawData(const std::string& fileName);

    void saveTxt(const std::string& fileName, const std::vector<std::string>& data);

    void saveBin(const std::string& fileName, const std::vector<std::string>& data);

    void loadRawData(const std::string& fileName, const std::string& password);

    void loadRawData(const std::string& fileName);

    std::vector<std::string> loadTxt(const std::string& fileName);

    std::vector<std::string> loadBin(const std::string& fileName);
};