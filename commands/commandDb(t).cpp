#include "commandDb(t).h"


CommandName CommandDb::strToAction(const std::string& str)
{
    if(str == "CREATE") return CommandName::Create;
    if(str == "SHOW") return CommandName::Show;
    if(str == "DELETE") return CommandName::Delete; 
    return CommandName::Unknown;
}

void CommandDb::Create(const std::string& typeName)
{
    Database db(typeName);
}

void CommandDb::Show(const std::string& fileName)
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

void CommandDb::Delete()
{

}

void CommandDb::Execute(const std::vector<std::string>& arr)
{
    CommandName cmd = strToAction(arr[1]);
    std::string fileName = arr[2];

    switch (cmd)
    {
    case CommandName::Create:
        Create("filename");
        break;

    case CommandName::Show:
        Show(fileName);
        break;

    case CommandName::Delete:
        Delete();
        break;

    case CommandName::Unknown:
        std::cout << "Error: Unknown operator" << std::endl;
        break;
    }
}