#include "parser.h"


std::vector<std::string> Parser::dbIntoArray(const std::string& path)
{
    SmartFile file(path, std::ios::in);

    return file.readAll();
}

void Parser::arrayIntoDB(const std::vector<std::string>& db, const std::string& path)
{
    int count {};

    SmartFile file(path, std::ios::out);

    for (int i = 1; i < db.size(); i++)
    {
        file.smartWrite(db[count] + "\n");
        count+=1;
    }
    file << db[db.size()-1];
}

std::vector<std::string> Parser::getLine(const std::vector<std::string>& db, int num)
{
    if (db.size() < num || num < 0) 
    {
        std::cout << "Error: You can't take a non-existent line." << std::endl;
        return {};
    }
    return Helper().strip(db[num], ',');
}

std::vector<std::string> Parser::getLine(const std::string& path, int num)
{
    std::vector db = dbIntoArray(path);

    return getLine(db, num);
}

std::vector<std::string> Parser::getColumn(const std::vector<std::string>& db, int num)
{
    std::vector<std::string> column {};

    if (Helper().strip(db[0], ',').size() < num || num < 0) 
    {
        std::cout << "Error: You can't take a non-existent column." << std::endl;
        return {};
    }
    
    for (int i = 0; i < db.size(); i++)
    {
        column.push_back(Helper().strip(db[i], ',')[num]);
    }
    
    return column;
}

std::vector<std::string> Parser::getColumn(const std::string& path, int num)
{
    std::vector<std::string> db = dbIntoArray(path);

    return getColumn(db, num);
}

std::string Parser::extractBetween(const std::string& line, char firstItem, char secondItem)
{
    int firstIndex = line.find_first_of(firstItem);
    int secondIndex = line.find_last_of(secondItem);
    std::string result = line.substr(firstIndex + 1, secondIndex - firstIndex - 1);

    return result;
}

std::string Parser::cutAfter(const std::string& line, char item)
{
    int index = line.find_first_of(item);
    std::string result = line.substr(0, index);

    return result;
}

std::string Parser::cutBefore(const std::string& line, char item)
{
    int index = line.find_first_of(item);
    std::string result = line.substr(index + 1);

    return result;
}