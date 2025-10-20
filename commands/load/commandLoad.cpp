#include "commandLoad.h"


void CommandLoad::load()
{
    if (ValidateFile().isTableExists(QUICK_SAVE_PATH) == false) 
    {
        std::cout << "ERROR: Data does not exist, please save it before loading" << std::endl;
        return;
    }

    UtilsFile().loadRawData(QUICK_SAVE_PATH);

    std::cout << "Data loaded" << std::endl;
}