#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "logic/helper.cpp"
#include "content/globals.cpp"

extern std::string globalDbName;

enum class CommandCol
{
    Add,
    Edit,
    Delete,
    Unknown
};

class Command_Col
{
    private:
    CommandCol strToAction(std::string str)
    { 
        if(str == "ADD") return CommandCol::Add;
        if(str == "EDIT") return CommandCol::Edit;
        if(str == "DELETE") return CommandCol::Delete;
        return CommandCol::Unknown;
    }


    std::string PathConstructor(std::string fileName, std::string extension)
    {
        const std::string path = "DataBases/";
        return path + fileName + extension;
    }

    bool CheckRows(std::string path)
    {
        std::ifstream file(path);
        std::string line;
        int count {0};

        while (std::getline(file, line))
        {
            count++;
            if (count > 1) return 0;
        }

        return 1;
    }

    void Add(std::string columnName)
    {
        std::string path = PathConstructor(globalDbName, ".txt");

        if (CheckRows(path) == false)
        {
            std::cout << "Error: Cannot adds columns if lines already exist." << std::endl;
            return;
        }

        std::ofstream file(path, std::ios::app);
        file << ',' << columnName;

        std::cout << "Column added in " << globalDbName << std::endl;
    }

    public:
    void Execute(std::vector<std::string> items)
    {
        CommandCol cmd = strToAction(items[1]);

        switch (cmd)
        {
        case CommandCol::Add:
            Add(items[2]);
            break;

        case CommandCol::Edit:
            std::cout << "Edit operation not implemented" << std::endl;
            break;

        case CommandCol::Delete:
            std::cout << "Delete operation not implemented" << std::endl;
            break;

        case CommandCol::Unknown:
          break;
        }
    }
};