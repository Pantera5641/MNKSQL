#include "utilsDb.h"


void UtilsDb::showTable(const std::vector<std::string>& db)
{
    std::vector<int> maxElementSize {};
    int numOfColumn = Helper().strip(db.at(0), COMMA).size();

    for (int i = 0; i < numOfColumn; i++)
    {
        std::vector<std::string> column = Parser().getColumn(db,i);

        auto item = std::max_element(column.begin(), column.end(),
        [](const std::string& a, const std::string& b)
        {return a.size() < b.size();});

        int maxLength = item->size();

        maxElementSize.push_back(maxLength);
    }

    for (int i = 0; i < numOfColumn; i++)
    { 
        std::vector<std::string> zeroLine = Parser().getLine(db, 0);

        int itemSize = maxElementSize[i] - zeroLine[i].size();

        std::cout << VERTICAL_BAR << SPACE << zeroLine[i] << Helper().repeat(itemSize + 2, SPACE);
    }
    std::cout << VERTICAL_BAR << std::endl;
    
    for (int i = 0; i < numOfColumn; i++)
    {
        int itemSize = maxElementSize[i];

        std::cout << VERTICAL_BAR <<  Helper().repeat(itemSize + 3, HYPHEN);
    }
    std::cout << VERTICAL_BAR << std::endl;

    int calumnSize = Parser().getColumn(db,0).size() - 1;
    for (int i = 0; i < calumnSize; i++)
    {
        std::vector<std::string> lines = Parser().getLine(db, i);

        for (int j = 0; j < numOfColumn; j++)
        {
            int itemSize = maxElementSize[j] - lines[j].size();
            std::cout << VERTICAL_BAR << SPACE << lines[j] << Helper().repeat(itemSize, SPACE) << Helper().repeat(2, SPACE);
        }
        std::cout << VERTICAL_BAR << std::endl;
    }
}