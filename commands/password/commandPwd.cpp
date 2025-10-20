#include "commandPwd.h"


CommandPwd::Commands CommandPwd::strToAction(const std::string& str)
{ 
    if(str == "SET") return Commands::Set;
    if(str == "EDIT") return Commands::Edit;
    return Commands::Unknown;
}

void CommandPwd::set(const std::string& fileName, const std::string& newPassword)
{
    std::string password {UtilsTable().loadFile(fileName).at(0)};

    if (password != (LEFT_PARENTHESIS + NONE + RIGHT_PARENTHESIS))
    {
        std::cout << "ERROR: This file already has a password, use the EDIT command to change it" << std::endl;
        return;
    }

    UtilsCommandPwd().setPassword(fileName, newPassword);

    std::cout << "Set to: " << newPassword << std::endl;
}

void CommandPwd::edit(const std::string& fileName, const std::string& oldPassword, const std::string& newPassword)
{
    std::string password {UtilsTable().loadFile(fileName).at(0)};

    if (password != (LEFT_PARENTHESIS + oldPassword + RIGHT_PARENTHESIS))
    {
        std::cout << "ERROR: Incorrect password" << std::endl;
        return;
    }

    UtilsCommandPwd().setPassword(fileName, newPassword);

    std::cout << "Password changed to: " << newPassword << std::endl;
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
            std::cout << "ERROR: Invalid arguments" << std::endl;
        }
        break;

    case Commands::Edit:
        try 
        {
            edit(items.at(2),items.at(3),items.at(4));
        } 
        catch (...) 
        {
            std::cout << "ERROR: Invalid arguments" << std::endl;
        }
        break;

    case Commands::Unknown:
        std::cout << "ERROR: Unknown command" << std::endl;
        break;
    }
}