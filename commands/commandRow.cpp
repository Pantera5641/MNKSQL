#include "commandRow.h"


CommandRow::Commands CommandRow::strToAction(std::string str)
{
    if(str == "ADD") return Commands::Add; 
    if(str == "REWRITE") return Commands::Rewrite; 
    if(str == "REMOVE") return Commands::Remove; 
    return Commands::Unknown;
}

void CommandRow::add(const std::string& argsString)
{
    DataStore& store = DataStore::getInstance();
    int descriptorSize {store.descriptor.size()};

    std::vector<std::string> args {Helper().strip(argsString, COMMA)};
    std::vector<std::string> fields(descriptorSize);

    if (descriptorSize == 0)
    {
        std::cout << "Error: At least 1 column is needed to create a row." << std::endl;
        return;
    }

    if (args.size() != descriptorSize)
    {
        std::cout << "Error: Invalid number of elements." << std::endl;
        return;
    }

    for (std::string item : args)
    {
        std::string userNameofField {Parser().cutAfter(item, EQUALS_SIGN)};
        std::string userField {Parser().cutBefore(item, EQUALS_SIGN)};

        for (int i = 0; i < descriptorSize; i++)
        {
            std::string nameofField {store.descriptor.getFieldNames()[i]};

            if (userNameofField == nameofField)
            {
                fields[i] = userField;
                break;
            }
        } 
    }

    store.addContainer(Helper().connect(fields, COMMA));

    std::cout << "Row added in database." << std::endl;
}

void CommandRow::rewrite(const std::string& indexString, const std::string& argsString)
{
    int index {};
    DataStore& store = DataStore::getInstance();

    try
    {
        index = std::stoi(indexString) - 1;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: Invalid number of row" << std::endl;
        return;
    }

    store.database[index] = store.descriptor.createContainer(argsString);

    std::cout << "Row was rewrite" << std::endl;
}

void CommandRow::remove(const std::string& indexString)
{
    int index {};
    DataStore& store = DataStore::getInstance();

    try
    {
        index = std::stoi(indexString) - 1;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: Invalid number of row" << std::endl;
        return;
    }

    store.database.erase(store.database.begin() + index);

    std::cout << "Row was deleted" << std::endl;
}

void CommandRow::execute(const std::vector<std::string>& items)
{
    Commands cmd = strToAction(items[1]);

    switch (cmd)
    {
    case Commands::Add:
        add(items[2]);
        break;
    case Commands::Rewrite:
        rewrite(items[2], items[3]);
        break;
    case Commands::Remove:
        remove(items[2]);
        break;
    case Commands::Unknown:
        std::cout << "Error: Unknown operation" << std::endl;
        break;
    }
}