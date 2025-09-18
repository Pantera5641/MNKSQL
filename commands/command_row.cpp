#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "logic/helper.cpp"
#include "content/globals.cpp"

extern std::string globalDbName;

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


    std::string PathConstructor(std::string fileName, std::string extension)
    {
        const std::string path = "DataBases/";
        return path + fileName + extension;
    }

    int CountRows(std::string path)
    {
        std::ifstream file(path);
        std::string line;
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
        std::string line;
        std::string userLine;
        int numberOfColumns;

        std::string path = PathConstructor(globalDbName, ".txt");
        
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
            std::cout << "Rewrite operation not implemented" << std::endl;
            break;
        case CommandRow::Delete:
            std::cout << "Delete operation not implemented" << std::endl;
            break;
        case CommandRow::Unknown:
            std::cout << "Error: Unknown operation" << std::endl;
          break;
        }
    }
};