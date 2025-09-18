#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>

#include "helper.cpp"

class Parser
{
    public:
    std::vector<std::string> DbIntoArray(std::string path)
    {
        std::vector<std::string> db {};
        std::string line;

        std::ifstream file(path);

        while (std::getline(file, line))
        {
            db.push_back(line);
        }
        
        return db;
    }

    std::vector<std::string> GetLine(std::vector<std::string> db, int num)
    {
        if (db.size() < num || num < 0) 
        {
            std::cout << "Error: You can't take a non-existent line." << std::endl;
            return {};
        }
        return Helper().Strip(db[num], ',');
    }

    std::vector<std::string> GetLine(std::string path, int num)
    {
        std::vector db = DbIntoArray(path);

        return GetLine(db, num);
    }

    std::vector<std::string> GetColumn(std::vector<std::string> db, int num)
    {
        std::vector<std::string> column {};

        if (Helper().Strip(db[0], ',').size() < num || num < 0) 
        {
            std::cout << "Error: You can't take a non-existent column." << std::endl;
            return {};
        }
        
        for (int i = 0; i < db.size(); i++)
        {
            column.push_back(Helper().Strip(db[i], ',')[num]);
        }
        
        return column;
    }

    std::vector<std::string> GetColumn(std::string path, int num)
    {
        std::vector<std::string> db = DbIntoArray(path);

        return GetColumn(db, num);
    }
};
