#include "file.h"
#include "dataStore/dataStore.h"


void saveTxt(const std::string& fileName)
{
    std::fstream file(TO_TABLE_PATH + fileName + ".txt", std::ios::out | std::ios::app);
    for (int i = 0; i < studentsList.size(); i++) 
    {
        file << connect(getLine(i), ',') << '\n';
    }
}

void saveBin(const std::string& fileName)
{
    std::fstream file(TO_TABLE_PATH + fileName + ".bin", std::ios::out | std::ios::app | std::ios::binary);

    for (int i = 0; i < studentsList.size(); i++)
    {
        std::string item {connect(getLine(i), ',')};
        int len = item.size();
        file.write(reinterpret_cast<const char*>(&len), sizeof(len));
        file.write(item.data(), len);  
    }
}

std::vector<std::string> loadTxt(const std::string& fileName)
{
    std::fstream file(TO_TABLE_PATH + fileName + ".txt", std::ios::in);

    std::vector<std::string> rawData {};
    std::string line {};

    while(std::getline(file, line)) 
    {
        rawData.push_back(line);
    }

    return rawData;
}

std::vector<std::string> loadBin(const std::string& fileName)
{
    std::fstream file(TO_TABLE_PATH + fileName, std::ios::in | std::ios::binary);
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