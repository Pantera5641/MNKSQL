#include "utilsFile.h"


void UtilsFile::saveTxt(const std::string& fileName, const std::vector<std::string>& data)
{
    std::fstream file(Path().construct(fileName), std::ios::out | std::ios::app);
    for (std::string item : data) 
    {
        file << item << '\n';
    }
}

void UtilsFile::saveBin(const std::string& fileName, const std::vector<std::string>& data)
{
    std::fstream file(Path().construct(fileName), std::ios::out | std::ios::app | std::ios::binary);

    for (std::string item : data)
    {
        int len = item.size();
        file.write(reinterpret_cast<const char*>(&len), sizeof(len));
        file.write(item.data(), len);  
    }
}

std::vector<std::string> UtilsFile::loadTxt(const std::string& fileName)
{
    std::fstream file(Path().construct(fileName), std::ios::in);

    std::vector<std::string> rawData {};
    std::string line {};

    while(std::getline(file, line)) 
    {
        rawData.push_back(line);
    }

    return rawData;
}

std::vector<std::string> UtilsFile::loadBin(const std::string& fileName)
{
    return {};
}