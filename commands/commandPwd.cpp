#include "commandPwd.h"


CommandPwd::Commands CommandPwd::strToAction(const std::string& str)
{ 
    if(str == "ADD") return Commands::Set;
    if(str == "EDIT") return Commands::Edit;
    return Commands::Unknown;
}

void CommandPwd::set(const std::string& fileName, const std::string& password)
{

}

void CommandPwd::edit(const std::string& fileName, const std::string& oldPassword, const std::string& newPassword)
{

}

void CommandPwd::execute(const std::vector<std::string>& items)
{
    Commands cmd = strToAction(items.at(1));

    switch (cmd)
    {
    case Commands::Set:
        try 
        {
            set(items.at(2),items.at(3));
        } 
        catch (...) 
        {
        
        }
        break;

    case Commands::Edit:
        try 
        {
            edit(items.at(2),items.at(3),items.at(4));
        } 
        catch (...) 
        {
        
        }
        break;

    case Commands::Unknown:
        break;
    }
}