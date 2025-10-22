#include "validateDb.h"

std::string ValidateDb::checkShowErrors()
{
    DataStore& store = DataStore::getInstance();
    if (store.descriptor.size() == 0) 
    {
        return EMPTY_DATABASE_DISPLAY_ERROR;
    }

    return NONE;
}