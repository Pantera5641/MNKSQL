#include <iostream>
#include <vector>
#include <string>

#include "logic/helper.h"
#include "logic/path.h"
#include "logic/smartFile.h"
#include "content/globals.h"


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

    bool CheckRows(std::string path)
    {
        SmartFile file(path, std::ios::in);
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
        std::string path = Path().Construct(globalDbName);

        if (CheckRows(path) == false)
        {
            std::cout << "Error: Cannot adds columns if lines already exist." << std::endl;
            return;
        }

        SmartFile file(path, std::ios::out | std::ios::app);
        file.Write(',' + columnName);

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