#include "commandView.h"


CommandView::Commands CommandView::strToAction(const std::string& str)
{ 
    if(str == "FILTER") return Commands::Filter;
    if(str == "SORT") return Commands::Sort;
    return Commands::Unknown;
}

void CommandView::filter(const std::string& arg)
{

}

void CommandView::sort(const std::string& column, const std::string& typeOfSort)
{

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
        
        }
        break;

    case Commands::Sort:
        try 
        {
            sort(items.at(2),items.at(3));
        } 
        catch (...) 
        {
        
        }
        break;

    case Commands::Unknown:
        break;
    }
}