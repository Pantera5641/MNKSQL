#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>

#include "logic/parser.h"
#include "logic/helper.h"
#include "logic/path.h"
#include "logic/smartFile.h"
#include "content/globals.h"


enum class CommandDb
{
    CreateTxt,
    CreateBin,
    Open,
    Show,
    Delete,
    Unknown
};

class Command_Db
{
    private:
    CommandDb strToAction(std::string str)
    {
        if(str == "CREATE") return CommandDb::CreateTxt;
        if(str == "CREATEBIN") return CommandDb::CreateBin;
        if(str == "OPEN") return CommandDb::Open;
        if(str == "SHOW") return CommandDb::Show;
        if(str == "DELETE") return CommandDb::Delete; 
        return CommandDb::Unknown;
    }

    void Create(std::string fileName, std::string extension)
    {
        std::filesystem::create_directories("DataBases");
        SmartFile file(Path().Construct(fileName, extension), std::ios::out);
        file.Write("id");
        std::cout << "DataBase " << fileName << " was created" << std::endl;
    }

    void CreateTxt(std::string fileName)
    {
        Create(fileName, ".txt");
    }

    void CreateBin(std::string fileName)
    {
        Create(fileName, ".bin");
    }

    void Open(std::string fileName)
    {
        globalDbName = fileName;
        std::cout << "Now you working with " << fileName << std::endl;
    }

    void Show(std::string fileName)
    {
        std::string path = Path().Construct(fileName);
        std::vector<std::string> db = Parser().DbIntoArray(path);
        std::vector<std::string> zeroLine = Parser().GetLine(db, 0);
        int zeroLineSize = zeroLine.size();

        std::vector<int> maxElementSize {};
        
        for (int i = 0; i < zeroLineSize; i++)
        {
            std::vector<std::string> column = Parser().GetColumn(db, i);

            auto item = std::max_element(column.begin(), column.end(),
            [](const std::string& a, const std::string& b)
            {return a.size() < b.size();});

            int maxLength = item->size();

            maxElementSize.push_back(maxLength);
        }

        for (int i = 0; i < zeroLineSize; i++)
        {
            int itemSize = maxElementSize[i] - zeroLine[i].size();

            std::cout << "| " << zeroLine[i] << Helper().Repeat(itemSize, ' ') << "  ";
        }
        std::cout << '|' << std::endl;
        
        for (int i = 0; i < zeroLineSize; i++)
        {
            int itemSize = maxElementSize[i];

            std::cout << '|' <<  Helper().Repeat(itemSize + 3, '-');
        }
        std::cout << '|' << std::endl;

        int calumnSize = Parser().GetColumn(db, 0).size() - 1;
        for (int i = 0; i < calumnSize; i++)
        {
            std::vector<std::string> line = Parser().GetLine(db, i + 1);

            for (int j = 0; j < zeroLineSize; j++)
            {
                int itemSize = maxElementSize[j] - line[j].size();
                std::cout << "| " << line[j] << Helper().Repeat(itemSize, ' ') << "  ";
            }
            std::cout << '|' << std::endl;
        }
    }

    void Delete(std::string fileName)
    {
        if (fileName == globalDbName) globalDbName = "";
        std::filesystem::remove(Path().Construct(fileName));
        
        std::cout << "Database " << fileName << " was deleted." << std::endl;
    }

    public:
    void Execute(std::vector<std::string> arr)
    {
        CommandDb cmd = strToAction(arr[1]);
        std::string fileName = arr[2];

        switch (cmd)
        {
        case CommandDb::CreateTxt:
            CreateTxt(fileName);
            break;
        
        case CommandDb::CreateBin:
            CreateBin(fileName);
            break;

        case CommandDb::Show:
            Show(fileName);
            break;
        
        case CommandDb::Open:
            Open(fileName);
            break;

        case CommandDb::Delete:
            Delete(fileName);
            break;

        case CommandDb::Unknown:
            std::cout << "Error: Unknown operator" << std::endl;
            break;
        }
    }
};