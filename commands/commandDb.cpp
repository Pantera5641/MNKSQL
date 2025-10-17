#include "commandDb.h"


CommandDb::Commands CommandDb::strToAction(const std::string& str)
{
    if(str == "SHOW") return Commands::Show;
    if(str == "CLEAN") return Commands::Clean; 
    return Commands::Unknown;
}

void CommandDb::show()
{
    std::vector<int> maxElementSize {};

    DataStore& store = DataStore::getInstance();
    auto descriptor = store.descriptor;
    
    for (int i = 0; i < descriptor.size(); i++)
    {
        std::vector<std::string> column = store.getColumn(i);

        auto item = std::max_element(column.begin(), column.end(),
        [](const std::string& a, const std::string& b)
        {return a.size() < b.size();});

        int maxLength = item->size();

        maxElementSize.push_back(maxLength);
    }

    for (int i = 0; i < descriptor.size(); i++)
    { 
        std::vector<std::string> zeroLine = descriptor.getFieldNames();

        int itemSize = maxElementSize[i] - zeroLine[i].size();

        std::cout << VERTICAL_BAR << SPACE << zeroLine[i] << Helper().repeat(itemSize + 2, SPACE);
    }
    std::cout << VERTICAL_BAR << std::endl;
    
    for (int i = 0; i < descriptor.size(); i++)
    {
        int itemSize = maxElementSize[i];

        std::cout << VERTICAL_BAR <<  Helper().repeat(itemSize + 3, HYPHEN);
    }
    std::cout << VERTICAL_BAR << std::endl;

    int calumnSize = store.getColumn(0).size() - 1;
    for (int i = 0; i < calumnSize; i++)
    {
        std::vector<std::string> lines = store.getLine(i);

        for (int j = 0; j < descriptor.size(); j++)
        {
            int itemSize = maxElementSize[j] - lines[j].size();
            std::cout << VERTICAL_BAR << SPACE << lines[j] << Helper().repeat(itemSize, SPACE) << Helper().repeat(2, SPACE);
        }
        std::cout << VERTICAL_BAR << std::endl;
    }
}

void CommandDb::clean()
{
    DataStore& store = DataStore::getInstance();
    std::string userInput {};

    std::cout << "This will delete all data from the database. Are you sure?(Y/N)" << std::endl;
    std::cin >> userInput;

    if (userInput == "Y")
    {
        store.database.clear();
        store.descriptor.clear();
        std::cout << "Database cleared." << std::endl;
    }
    else if (userInput == "N")
    {
        return;
    }
    else
    {
        std::cout << "Syntax error." << std::endl;
        return;
    }
}

void CommandDb::execute(const std::vector<std::string>& items)
{
    Commands cmd = strToAction(items.at(1));

    switch (cmd)
    {
    case Commands::Show:
        show();
        break;

    case Commands::Clean:
        clean();
        break;

    case Commands::Unknown:
        std::cout << "Error: Unknown operator" << std::endl;
        break;
    }
}