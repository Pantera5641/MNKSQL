#include "commandFile.h"


CommandFile::Commands CommandFile::strToAction(const std::string& str)
{
    if(str == "SAVE") return Commands::Save;
    if(str == "LOAD") return Commands::Load; 
    return Commands::Unknown;
}

void CommandFile::saveTxt(const std::string& fileName, const std::vector<std::string>& data)
{
    std::fstream file(Path().construct(fileName), std::ios::out | std::ios::app);
    for (std::string item : data) 
    {
        file << item << '\n';
    }
}

void CommandFile::saveBin(const std::string& fileName, const std::vector<std::string>& data)
{
    std::fstream file(Path().construct(fileName), std::ios::out | std::ios::app | std::ios::binary);

    for (std::string item : data)
    {
        int len = item.size();
        file.write(reinterpret_cast<const char*>(&len), sizeof(len));
        file.write(item.data(), len);  
    }
}

void CommandFile::save(const std::string& fileName, const std::string& password)
{
    DataStore& store = DataStore::getInstance();
    std::vector<std::string> rawData {};

    rawData.push_back(LEFT_PARENTHESIS + password + RIGHT_PARENTHESIS);
    rawData.push_back(Helper().connect(store.descriptor.getAllField(), COMMA));

    for (Container item : store.database)
    {
        rawData.push_back(Helper().connect(item.getFields(), COMMA));
    }

    std::filesystem::create_directories("tables");

    if (Parser().cutBefore(fileName, DOT) == "txt") 
    {
        saveTxt(fileName, rawData);
    }
    else 
    {
        saveBin(fileName, rawData);
    }

    std::cout << "Your data has been saved to " << fileName << std::endl;
}

void CommandFile::load(const std::string& fileName, const std::string& password)
{

}

void CommandFile::remove(const std::string& fileName, const std::string& password)
{
    std::filesystem::remove(Path().construct(fileName));
    
    std::cout << "Table " << fileName << " was deleted." << std::endl;
}

void CommandFile::execute(const std::vector<std::string>& items)
{
    Commands cmd = strToAction(items[1]);

    switch (cmd)
    {
    case Commands::Save:
        try 
        {
            save(items.at(2), items.at(3));
        } 
        catch (...) 
        {
            save(items.at(2));
        }
        break;

    case Commands::Load:
        try 
        {
            load(items.at(2), items.at(3));
        } 
        catch (...) 
        {
            load(items.at(2));
        }
        break;

    case Commands::Unknown:
        std::cout << "Error: Unknown operator" << std::endl;
        break;
    }
}