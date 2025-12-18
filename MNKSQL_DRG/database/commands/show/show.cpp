#include "show.h"


void drawBarrier(int numOfColumn, std::vector<int> maxElementSize)
{
    for (int i = 0; i < numOfColumn; i++)
    {
        int itemSize = maxElementSize[i];

        std::cout << "::" <<  repeat(itemSize + 3, ':');
    }
    std::cout << "::" << std::endl;
}

void showTable()
{
    std::string path {TO_LOCALIZATION_PATH + globalLanguage + "/messagesByParam/showCommand.txt"};
    std::vector<std::string> zeroLine
    {
        getParam("id", path),
        getParam("lastName", path),
        getParam("firstName", path),
        getParam("surname", path),
        getParam("yearOfBirth", path),
        getParam("yearOfAdmission", path),
        getParam("course", path),
        getParam("group", path)
    };

    std::vector<int> maxElementSize {2};
    int numOfColumn {8};
    for (int i = 1; i < numOfColumn; i++)
    {
        std::vector<std::string> column {getColumn(i - 1)};
        column.push_back(zeroLine.at(i));

        int maxLength = getMaxLength(column);

        maxElementSize.push_back(maxLength);
    }

    drawBarrier(numOfColumn, maxElementSize);

    for (int i = 0; i < numOfColumn; i++)
    { 
        int itemSize = maxElementSize[i] - utf8Length(zeroLine[i]);

        std::cout << "::" << ' ' << zeroLine[i] << repeat(itemSize + 2, ' ');
    }
    std::cout << "::" << std::endl;
    
    drawBarrier(numOfColumn, maxElementSize);

    int columnSize = getColumn(0).size();
    for (int i = 0; i < columnSize; i++)
    {
        std::vector<std::string> lines {std::to_string(i + 1)};
        std::vector<std::string> additionalLines {getLine(i)};
        lines.insert(lines.end(), additionalLines.begin(), additionalLines.end());

        for (int j = 0; j < numOfColumn; j++)
        {
            int itemSize = maxElementSize[j] - utf8Length(lines[j]);
            std::cout << "::" << ' ' << lines[j] << repeat(itemSize, ' ') << repeat(2, ' ');
        }
        std::cout << "::" << std::endl;
    }

    drawBarrier(numOfColumn, maxElementSize);
}