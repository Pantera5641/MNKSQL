#include "commandFile.h"


CommandFile::Commands CommandFile::strToAction(const std::string& str)
{
    if(str == "SAVE") return Commands::Save;
    if(str == "LOAD") return Commands::Load; 
    if(str == "DELETE") return Commands::Remove; 
    return Commands::Unknown;
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
        UtilsFile().saveTxt(fileName, rawData);
    }
    else 
    {
        UtilsFile().saveBin(fileName, rawData);
    }

    std::cout << "Your data has been saved to " << fileName << std::endl;
}

void CommandFile::load(const std::string& fileName, const std::string& password)
{
    DataStore& store = DataStore::getInstance();
    std::vector<std::string> rawData {};

    if (Parser().cutBefore(fileName, DOT) == "txt") 
    {
        rawData = UtilsFile().loadTxt(fileName);
    }
    else
    {
        rawData = UtilsFile().loadBin(fileName);
    }

    //password logic

    store.descriptor.clear();
    store.descriptor.fill(rawData.at(1));
    
    for (int i = 2; i < rawData.size(); i++)
    {
        store.addContainer(rawData.at(i));
    }
    
    std::cout << "Your data has been load from " << fileName << std::endl;
}

void CommandFile::remove(const std::string& fileName, const std::string& password)
{
    std::filesystem::remove(Path().construct(fileName));
    
    std::cout << "Table " << fileName << " was deleted." << std::endl;
}

void CommandFile::execute(const std::vector<std::string>& items)
{
    Commands cmd = strToAction(items.at(1));

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
    
    case Commands::Remove:
        try 
        {
            remove(items.at(2), items.at(3));
        } 
        catch (...) 
        {

        }
        break;

    case Commands::Unknown:
        std::cout << "Error: Unknown operator" << std::endl;
        break;
    }
}