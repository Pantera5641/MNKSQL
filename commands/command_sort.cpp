#include <iostream>
#include <vector>
#include <string>
#include <functional>

#include "logic/helper.h"
#include "content/parser.h"
#include "logic/path.h"
#include "logic/smartFile.h"
#include "content/globals.h"


enum class CommandSort
{
    Ascending,
    Descending,
    Unknown
};

class Command_Sort
{
    private:
    CommandSort strToAction(std::string str)
    {
        if(str == "ASC") return CommandSort::Ascending; 
        if(str == "DESC") return CommandSort::Descending; 
        return CommandSort::Unknown;
    }

    void SortBy(std::function<void(std::vector<std::string>&)> sortAlg, int num)
    {
        std::string path = Path().Construct(globalDbName, ".txt");
        std::vector<std::string> db = Parser().DbIntoArray(path);
        std::vector<std::string> SortedDb = sortAlg(db);

        SmartFile file(path, std::ios::out);
        for (int i = 0; i < SortedDb.size; i++)
        {
            file << SortedDb[i] << "\n";
        }
    }
    

    void AscendingBy(int num)
    {
        SortBy([](std::vector<std::string> db, num))
        {
            
        }
    }

    void DescendingBy()
    {

    }

    public:
    void Execute(std::vector<std::string> items)
    {
        CommandSort cmd = strToAction(items[1]);

        switch (cmd)
        {
        case CommandSort::Ascending:
            Ascending();
            break;
        case CommandSort::Descending:
            Descending();
            break;
        case CommandSort::Unknown:
            std::cout << "Error: Unknown operation" << std::endl;
          break;
        }
    }
};