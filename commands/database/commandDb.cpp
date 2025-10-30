#include "commandDb.h"


CommandDb::Commands CommandDb::strToAction(const std::string& str)
{
    if(str == "SHOW") return Commands::Show;
    if(str == "CLEAN") return Commands::Clean; 
    if(str == "TEMPSORT") return Commands::TempSort; 
    return Commands::Unknown;
}

void CommandDb::show()
{
    std::string error {ValidateDb().checkShowErrors()};
    if (error != NONE) 
    {
        std::cout << error << std::endl;
        return;
    }

    DataStore& store = DataStore::getInstance();
    std::vector<std::string> db {Helper().connect(store.descriptor.getFieldNames(), COMMA)};

    for (Container item : store.database) 
    {
        db.push_back(Helper().connect(item.getFields(), COMMA));
    } 

    
    UtilsShow().showTable(db);
}

void CommandDb::clean()
{
    DataStore& store = DataStore::getInstance();
    std::string userInput {};

    std::cout << CONFIRM_DATABASE_DELETE_PROMPT << std::endl;
    std::cin >> userInput;

    if (userInput == "Y")
    {
        store.database.clear();
        store.descriptor.clear();
        std::cout << DATABASE_CLEARED_MESSAGE << std::endl;
    }
    else if (userInput == "N")
    {
        return;
    }
    else
    {
        std::cout << SYNTAX_ERROR << std::endl;
        return;
    }
}

void CommandDb::bubbleSort(int index) 
{
    DataStore& store = DataStore::getInstance();

    for (int i = 0; i < store.database.size() - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < store.database.size() - i - 1; j++) 
        {
            if (store.database.at(j).getItem(index) > store.database.at(j + 1).getItem(index)) 
            {
                // меняем местами элементы
                Container temp = store.database.at(j);
                store.database.at(j) = store.database.at(j + 1);
                store.database.at(j + 1) = temp;
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

void CommandDb::tempSort(const std::string& fieldsString)
{   
    DataStore& store = DataStore::getInstance();

    std::vector<std::string> fields {Helper().strip(fieldsString, COMMA)};

    for (int i = 0; i < fields.size(); i++) 
    {
        int columnIndex {store.descriptor.getFieldNameIndex(fields.at(i))};

        bubbleSort(columnIndex);
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
    
    //temp
    case Commands::TempSort:
        tempSort(items.at(2));
        break;

    case Commands::Unknown:
        std::cout << UNKNOWN_OPERATOR_ERROR << std::endl;
        break;
    }
}