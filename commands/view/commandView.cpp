#include "commandView.h"


CommandView::Commands CommandView::strToAction(const std::string& str)
{ 
    if(str == "FILTER") return Commands::Filter;
    if(str == "SORT") return Commands::Sort;
    return Commands::Unknown;
}

void CommandView::filter(const std::string& arg)
{
    std::cout << COMMAND_NOT_IMPLEMENTED_ERROR << std::endl;
}

void CommandView::sort(const std::string& column, const std::string& typeOfSort)
{
    std::cout << COMMAND_NOT_IMPLEMENTED_ERROR << std::endl;
}

void CommandView::execute(const std::vector<std::string>& items)
{
    Commands cmd = strToAction(items.at(1));

    switch (cmd)
    {
    case Commands::Filter:
        try 
        {
            filter(items.at(2));
        } 
        catch (...) 
        {
            std::cout << INVALID_ARGUMENTS_ERROR << std::endl;
        }
        break;

    case Commands::Sort:
        try 
        {
            sort(items.at(2),items.at(3));
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