#include "utilsFile.h"


void UtilsFile::saveRawData(const std::string& fileName, const std::string& password)
{
    DataStore& store = DataStore::getInstance();
    std::vector<std::string> rawData {};

    rawData.push_back(LEFT_PARENTHESIS + password + RIGHT_PARENTHESIS);
    rawData.push_back(Helper().connect(store.descriptor.getAllField(), COMMA));

    for (Container item : store.database)
    {
        rawData.push_back(Helper().connect(item.getFields(), COMMA));
    }

    std::filesystem::remove(Path().construct(fileName));

    if (Parser().cutBefore(fileName, DOT) == "txt")
    {
        saveTxt(fileName, rawData);
    }
    else 
    {
        saveBin(fileName, rawData);
    }
}

void UtilsFile::saveRawData(const std::string& fileName)
{
    saveRawData(fileName, std::string());
}

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

void UtilsFile::loadRawData(const std::string& fileName, const std::string& password)
{
    DataStore& store = DataStore::getInstance();
    std::vector<std::string> rawData {};

    if (Parser().cutBefore(fileName, DOT) == "txt") 
    {
        rawData = loadTxt(fileName);
    }
    else
    {
        rawData = loadBin(fileName);
    }

    //password logic

    store.descriptor.clear();
    store.descriptor.fill(rawData.at(1));
    
    for (int i = 2; i < rawData.size(); i++)
    {
        store.addContainer(rawData.at(i));
    }
}

void UtilsFile::loadRawData(const std::string& fileName)
{
    loadRawData(fileName, std::string());
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