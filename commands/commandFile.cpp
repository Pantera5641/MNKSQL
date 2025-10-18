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
    UtilsFile().saveRawData(fileName, password);

    std::cout << "Your data has been saved to " << fileName << std::endl;
}

void CommandFile::load(const std::string& fileName, const std::string& password)
{
    UtilsFile().loadRawData(fileName, password);
    
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