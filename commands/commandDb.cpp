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

        std::cout << VERTICAL_BAR << SPACE << zeroLine[i] << Helper().Repeat(itemSize + 2, SPACE);
    }
    std::cout << VERTICAL_BAR << std::endl;
    
    for (int i = 0; i < descriptor.size(); i++)
    {
        int itemSize = maxElementSize[i];

        std::cout << VERTICAL_BAR <<  Helper().Repeat(itemSize + 3, HYPHEN);
    }
    std::cout << VERTICAL_BAR << std::endl;

    int calumnSize = store.getColumn(0).size() - 1;
    for (int i = 0; i < calumnSize; i++)
    {
        std::vector<std::string> lines = store.getLine(i);

        for (int j = 0; j < descriptor.size(); j++)
        {
            int itemSize = maxElementSize[j] - lines[j].size();
            std::cout << VERTICAL_BAR << SPACE << lines[j] << Helper().Repeat(itemSize, SPACE) << Helper().Repeat(2, SPACE);
        }
        std::cout << VERTICAL_BAR << std::endl;
    }
}

void CommandDb::clean()
{

}

void CommandDb::execute(const std::vector<std::string>& arr)
{
    Commands cmd = strToAction(arr[1]);

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