#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "logic/helper.h"
#include "logic/path.h"
#include "content/globals.h"


enum class CommandRow
{
    Add,
    Rewrite,
    Delete,
    Unknown
};

class Command_Row
{
    private:
    CommandRow strToAction(std::string str)
    {
        if(str == "ADD") return CommandRow::Add; 
        if(str == "REWRITE") return CommandRow::Rewrite; 
        if(str == "DELETE") return CommandRow::Delete; 
        return CommandRow::Unknown;
    }

    int CountRows(std::string path)
    {
        std::ifstream file(path);
        std::string line {};
        int count {0};

        while (std::getline(file, line))
        {
            count++;
        }
        
        file.close();

        return count;
    }

    void Add()
    {
        std::string line {};
        std::string userLine {};
        int numberOfColumns {};

        std::string path = Path().Construct(globalDbName, ".txt");
        
        std::ifstream file(path);

        std::getline(file, line);
        std::vector<std::string> items = Helper().Strip(line, ',');
        items.erase(items.begin());
        numberOfColumns = items.size();

        if (numberOfColumns == 0)
        {
            std::cout << "Error: At least 1 column is needed to create a row." << std::endl;
            return;
        }

        std::cout << "Fill in all fields:" << std::endl;
        std::cout << Helper().Connect(items, ' ') << std::endl;
        std::getline(std::cin, userLine);

        std::vector<std::string> userItems = Helper().Strip(userLine, ' ');

        if (userItems.size() != numberOfColumns)
        {
            std::cout << "Error: Invalid number of elements." << std::endl;
            return;
        }

        std::ofstream file1(path, std::ios::app);
        file1 << "\n" << std::to_string(CountRows(path)) << ',' << Helper().Connect(userItems, ',');

        std::cout << "Row added in " << globalDbName << std::endl;
    }

    void Rewrite(std::string rowNumStr)
    {
        int count {};
        int rowNum {};
        std::string line {};
        std::string userLine {};

        std::string path = Path().Construct(globalDbName, ".txt");
        std::vector<std::string> db = Parser().DbIntoArray(path);

        try
        {
            rowNum = std::stoi(rowNumStr);
        }
        catch(const std::exception& e)
        {
            std::cout << "Error: Invalid number of row" << std::endl;
            return;
        }
        
        std::vector<std::string> zeroLine = Helper().Strip(db[0], ',');
        zeroLine.erase(zeroLine.begin());

        std::cout << "Fill in all fields:" << std::endl;
        std::cout << Helper().Connect(zeroLine, ' ') << std::endl;
        std::getline(std::cin, userLine);

        std::vector<std::string> userItems = Helper().Strip(userLine, ' ');
        db[rowNum] = std::to_string(rowNum) + "," + Helper().Connect(userItems, ',');

        Parser().ArrayIntoDB(db, path);
        std::cout << "Row was rewrite" << std::endl;
    }

    void Delete(std::string rowNumStr)
    {
        int count {};
        int rowNum {};
        std::string line {};
        std::string userLine {};

        std::string path = Path().Construct(globalDbName, ".txt");
        std::vector<std::string> db = Parser().DbIntoArray(path);

        try
        {
            rowNum = std::stoi(rowNumStr);
        }
        catch(const std::exception& e)
        {
            std::cout << "Error: Invalid number of row" << std::endl;
            return;
        }

        db.erase(db.begin()+rowNum);

        for (int i = 1; i < db.size(); i++)
        {
            std::vector<std::string> line = Helper().Strip(db[i], ',');
            line[0] = std::to_string(i);
            db[i] = Helper().Connect(line, ',');
        }

        Parser().ArrayIntoDB(db, path);
        std::cout << "Row was deleted" << std::endl;
    }

    public:
    void Execute(std::vector<std::string> items)
    {
        CommandRow cmd = strToAction(items[1]);

        switch (cmd)
        {
        case CommandRow::Add:
            Add();
            break;
        case CommandRow::Rewrite:
            Rewrite(items[2]);
            break;
        case CommandRow::Delete:
            Delete(items[2]);
            break;
        case CommandRow::Unknown:
            std::cout << "Error: Unknown operation" << std::endl;
          break;
        }
    }
};