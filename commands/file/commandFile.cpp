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
    std::string error {ValidateFile().checkSaveErrors(fileName, password)};
    if (error != NONE) 
    {
        std::cout << error << std::endl;
        return;
    }

    UtilsTable().saveRawData(fileName, password);

    std::cout << DATA_SAVED_TO_PATH_MESSAGE << fileName << std::endl;
}

void CommandFile::load(const std::string& fileName, const std::string& password)
{
    std::string error {ValidateFile().checkLoadAndRemoveErrors(fileName, password)};
    if (error != NONE) 
    {
        std::cout << error << std::endl;
        return;
    }

    UtilsTable().loadRawData(fileName, password);
    
    std::cout << DATA_LOADED_FROM_PATH_MESSAGE << fileName << std::endl;
}

void CommandFile::remove(const std::string& fileName, const std::string& password)
{
    std::string error {ValidateFile().checkLoadAndRemoveErrors(fileName, password)};
    if (error != NONE) 
    {
        std::cout << error << std::endl;
        return;
    }

    std::filesystem::remove(Path().construct(fileName));
    
    std::cout << TABLE_DELETED_MESSAGE << fileName << std::endl;
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
            remove(items.at(2));
        }
        break;

    case Commands::Unknown:
        std::cout << UNKNOWN_OPERATOR_ERROR << std::endl;
        break;
    }
}