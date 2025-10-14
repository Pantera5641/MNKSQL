#include "dataStore.h"


DataStore& DataStore::getInstance()
{
    static DataStore instance;
    return instance;
}

void DataStore::newDescriptor(const std::string& argsString)
{
    Descriptor descriptor(argsString);
    this->descriptor = descriptor;
}

std::vector<std::string> DataStore::getLine(int num)
{
    return database[num].getFields();
}

std::vector<std::string> DataStore::getColumn(int num)
{
    std::vector<std::string> column {};
    column.push_back(descriptor.getFieldNames()[num]);
    
    for (Container str : database)
    {
       column.push_back(str.getItem(num));
    }

    return column;
}