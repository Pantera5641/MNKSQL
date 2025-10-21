#include "commandLoad.h"


void CommandLoad::load()
{
    std::string error {ValidateFile().checkLoadAndRemoveErrors(QUICK_SAVE_PATH, NONE)};
    if (error != NONE) 
    {
        std::cout << error << std::endl;
        return;
    }

    UtilsTable().loadRawData(QUICK_SAVE_PATH);

    std::cout << "Data loaded" << std::endl;
}