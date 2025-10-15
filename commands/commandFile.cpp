#include "commandFile.h"


CommandFile::Commands CommandFile::strToAction(const std::string& str)
{
    if(str == "SAVE") return Commands::Save;
    if(str == "LOAD") return Commands::Load; 
    return Commands::Unknown;
}

void CommandFile::save(const std::string& fileName)
{

}

void CommandFile::load(const std::string& fileName)
{

}

void CommandFile::execute(const std::vector<std::string>& items)
{
    Commands cmd = strToAction(items[1]);

    switch (cmd)
    {
    case Commands::Save:
        save(items[2]);
        break;

    case Commands::Load:
        load(items[2]);
        break;

    case Commands::Unknown:
        std::cout << "Error: Unknown operator" << std::endl;
        break;
    }
}