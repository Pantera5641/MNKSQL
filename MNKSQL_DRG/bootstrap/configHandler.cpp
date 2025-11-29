#include "configHandler.h"


std::string getParam(const std::string& paramName, const std::string& path)
{
    std::string line {};
    std::fstream file(path, std::ios::in);

    while (std::getline(file, line)) 
    {
        if (cutAfter(line, '=') == paramName) 
        {
            return cutBefore(line, '=');
        }
    }

    return std::string();
}

void setParam(const std::string& paramName, const std::string& newParam)
{
    std::string line {};
    std::vector<std::string> lines {};
    std::fstream file(CONFIG_PATH, std::ios::in);

    while (std::getline(file, line)) 
    {
        lines.push_back(line);
    }

    file.close();
    
    file.open(CONFIG_PATH, std::ios::out | std::ios::trunc);

    for (int i = 0; i < lines.size(); i++)
    {
        if (cutAfter(lines.at(i), '=') == paramName) 
        {
            lines.at(i) = cutAfter(lines.at(i), '=') + '=' + newParam;
        }
        file << lines.at(i) + '\n';
    }
}