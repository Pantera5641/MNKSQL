#pragma once
#include <vector>
#include <fstream>
#include <filesystem>

#include "path.h"
#include "symbols.h"
#include "types.h"
#include "dataStore.h"


struct UtilsTable
{
    private:
    void saveTxt(const std::string& fileName, const std::vector<std::string>& data);

    void saveBin(const std::string& fileName, const std::vector<std::string>& data);

    std::vector<std::string> loadTxt(const std::string& fileName);

    std::vector<std::string> loadBin(const std::string& fileName);

    public:
    void saveRawData(const std::string& fileName, const std::string& password = NONE);

    void loadRawData(const std::string& fileName, const std::string& password = NONE);

    void saveFile(const std::string& fileName, const std::vector<std::string>& data);

    std::vector<std::string> loadFile(const std::string& fileName);
};