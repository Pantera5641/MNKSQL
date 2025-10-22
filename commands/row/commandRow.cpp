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
    std::string error {ValidateRow().checkAddErrors(argsString)};
    if (error != NONE) 
    {
        std::cout << error << std::endl;
        return;
    }

    DataStore& store = DataStore::getInstance();
    int descriptorSize {store.descriptor.size()};

    std::vector<std::string> args {Helper().strip(argsString, COMMA)};
    std::vector<std::string> fields(descriptorSize);

    for (std::string item : args)
    {
        std::string userNameOfField {Parser().cutAfter(item, EQUALS_SIGN)};
        std::string userField {Parser().cutBefore(item, EQUALS_SIGN)};

        for (int i = 0; i < descriptorSize; i++)
        {
            std::string nameOfField {store.descriptor.getFieldNames()[i]};

            if (userNameOfField == nameOfField)
            {
                if (UtilsCommandRow().validator(userField, i) != true) 
                {
                    std::cout << "Error in value:" << userNameOfField << std::endl;
                    return;
                }

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
    std::string error {ValidateRow().checkRewriteErrors(indexString, argsString)};
    if (error != NONE) 
    {
        std::cout << error << std::endl;
        return;
    }

    int index {std::stoi(indexString) - 1};
    DataStore& store = DataStore::getInstance();

    store.database[index] = store.descriptor.createContainer(argsString);

    std::cout << "Row was rewrite" << std::endl;
}

void CommandRow::remove(const std::string& indexString)
{
    std::string error {ValidateRow().checkRemoveErrors(indexString)};
    if (error != NONE) 
    {
        std::cout << error << std::endl;
        return;
    }

    int index {std::stoi(indexString) - 1};
    DataStore& store = DataStore::getInstance();

    store.database.erase(store.database.begin() + index);

    std::cout << "Row was deleted" << std::endl;
}

void CommandRow::execute(const std::vector<std::string>& items)
{
    Commands cmd = strToAction(items.at(1));

    switch (cmd)
    {
    case Commands::Add:
        try 
        {
            add(items.at(2));
        } 
        catch (...) 
        {
        
        }
    
        break;

    case Commands::Rewrite:
        try 
        {
            rewrite(items.at(2), items.at(3));
        } 
        catch (...) 
        {
        
        }
    
        break;

    case Commands::Remove:
        try 
        {
            remove(items.at(2));
        } 
        catch (...) 
        {
        
        }
        break;

    case Commands::Unknown:
        std::cout << "ERROR: Unknown operation" << std::endl;
        break;
    }
}