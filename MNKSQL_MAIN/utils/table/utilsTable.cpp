#include "utilsTable.h"


void UtilsTable::saveTxt(const std::string& fileName, const std::vector<std::string>& data)
{
    std::fstream file(Path().construct(fileName), std::ios::out | std::ios::app);
    for (std::string item : data) 
    {
        file << item << '\n';
    }
}

void UtilsTable::saveBin(const std::string& fileName, const std::vector<std::string>& data)
{
    std::fstream file(Path().construct(fileName), std::ios::out | std::ios::app | std::ios::binary);

    for (std::string item : data)
    {
        int len = item.size();
        file.write(reinterpret_cast<const char*>(&len), sizeof(len));
        file.write(item.data(), len);  
    }
}

std::vector<std::string> UtilsTable::loadTxt(const std::string& fileName)
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

std::vector<std::string> UtilsTable::loadBin(const std::string& fileName)
{
    std::fstream file(Path().construct(fileName), std::ios::in | std::ios::binary);
    std::vector<std::string> lines {};

    while (file.peek() != EOF) 
    {
        int len {};
        file.read(reinterpret_cast<char*>(&len), sizeof(len));

        std::string line(len, '\0');
        file.read(line.data(), len);

        lines.push_back(line);
    }

    return lines;
}

void UtilsTable::saveRawData(const std::string& fileName, const std::string& password)
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

    saveFile(fileName, rawData);
}

void UtilsTable::loadRawData(const std::string& fileName, const std::string& password)
{
    DataStore& store = DataStore::getInstance();
    std::vector<std::string> rawData {};

    rawData = loadFile(fileName);
    store.descriptor.clear();
    store.descriptor.fill(rawData.at(1));
    
    for (int i = 2; i < rawData.size(); i++)
    {
        store.addContainer(rawData.at(i));
    }
}

void UtilsTable::saveFile(const std::string& fileName, const std::vector<std::string>& data)
{
    std::filesystem::remove(Path().construct(fileName));

    if (Parser().cutBefore(fileName, DOT) == "txt")
    {
        saveTxt(fileName, data);
    }
    else 
    {
        saveBin(fileName, data);
    }
}

std::vector<std::string> UtilsTable::loadFile(const std::string& fileName)
{
    if (Parser().cutBefore(fileName, DOT) == "txt")
    {
        return loadTxt (fileName);
    }

    return loadBin(fileName);
}