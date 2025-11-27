#include "show.h"


void showTable()
{
    std::vector<std::string> zeroLine
    {
        "id",
        "lastName",
        "firstName",
        "surname",
        "yearOfBirth",
        "yearOfAdmission",
        "course",
        "group"
    };

    std::vector<int> maxElementSize {2};
    int numOfColumn {8};
    for (int i = 1; i < numOfColumn; i++)
    {
        std::vector<std::string> column {getColumn(i - 1)};
        column.push_back(zeroLine.at(i));

        auto item = std::max_element(column.begin(), column.end(),
        [](const std::string& a, const std::string& b)
        {return a.size() < b.size();});

        int maxLength = item->size();

        maxElementSize.push_back(maxLength);
    }

    for (int i = 0; i < numOfColumn; i++)
    {
        int itemSize = maxElementSize[i];

        std::cout << "::" <<  repeat(itemSize + 3, ':');
    }
    std::cout << "::" << std::endl;

    for (int i = 0; i < numOfColumn; i++)
    { 
        int itemSize = maxElementSize[i] - zeroLine[i].size();

        std::cout << "::" << ' ' << zeroLine[i] << repeat(itemSize + 2, ' ');
    }
    std::cout << "::" << std::endl;
    
    for (int i = 0; i < numOfColumn; i++)
    {
        int itemSize = maxElementSize[i];

        std::cout << "::" <<  repeat(itemSize + 3, ':');
    }
    std::cout << "::" << std::endl;

    int columnSize = getColumn(0).size();
    for (int i = 0; i < columnSize; i++)
    {
        std::vector<std::string> lines {std::to_string(i + 1)};
        std::vector<std::string> additionalLines {getLine(i)};
        lines.insert(lines.end(), additionalLines.begin(), additionalLines.end());

        for (int j = 0; j < numOfColumn; j++)
        {
            int itemSize = maxElementSize[j] - lines[j].size();
            std::cout << "::" << ' ' << lines[j] << repeat(itemSize, ' ') << repeat(2, ' ');
        }
        std::cout << "::" << std::endl;
    }
}