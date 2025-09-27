#include "helper.h"


std::vector<std::string> Helper::Strip(const std::string& str, char toRemove)
{
    std::vector<std::string> vector;
    std::string item;

    std::istringstream iss(str);

    while (std::getline(iss, item, toRemove))
    {
        item.erase(std::remove(item.begin(), item.end(), toRemove), item.end());
        vector.push_back(item);
    }

    return vector;
}

std::string Helper::Connect(const std::vector<std::string>& vec, char arg)
{
    std::string line;

    for (std::string item : vec)
    {
        line.append(item + arg);
    }

    line.pop_back();

    return line;
}

std::string Helper::Repeat(int num, char item)
{
    std::string result {};

    for (int i = 0; i < num; i++)
    {
        result+= item;
    }
    
    return result;
}

void Helper::PrintTxt(const std::string& path)
{
    std::string line;

    std::ifstream file(path);

    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }
}