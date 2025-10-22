#include "commandPwd.h"


CommandPwd::Commands CommandPwd::strToAction(const std::string& str)
{ 
    if(str == "SET") return Commands::Set;
    if(str == "EDIT") return Commands::Edit;
    return Commands::Unknown;
}

void CommandPwd::set(const std::string& fileName, const std::string& newPassword)
{
    std::string error {ValidatePwd().checkSetErrors(fileName, newPassword)};
    if (error != NONE) 
    {
        std::cout << error << std::endl;
        return;
    }

    UtilsCommandPwd().setPassword(fileName, newPassword);

    std::cout << PASSWORD_SET_MESSAGE << newPassword << std::endl;
}

void CommandPwd::edit(const std::string& fileName, const std::string& oldPassword, const std::string& newPassword)
{
    std::string error {ValidatePwd().checkEditErrors(fileName, newPassword, newPassword)};
    if (error != NONE) 
    {
        std::cout << error << std::endl;
        return;
    }

    UtilsCommandPwd().setPassword(fileName, newPassword);

    std::cout << PASSWORD_CHANGED_MESSAGE << newPassword << std::endl;
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
            std::cout << INVALID_ARGUMENTS_ERROR << std::endl;
        }
        break;

    case Commands::Edit:
        try 
        {
            edit(items.at(2),items.at(3),items.at(4));
        } 
        catch (...) 
        {
            std::cout << INVALID_ARGUMENTS_ERROR << std::endl;
        }
        break;

    case Commands::Unknown:
        std::cout << UNKNOWN_OPERATOR_ERROR << std::endl;
        break;
    }
}