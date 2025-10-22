#include "commandSave.h"


void CommandSave::save()
{
    std::string error {ValidateFile().checkSaveErrors(QUICK_SAVE_PATH, NONE)};
    if (error != NONE) 
    {
        std::cout << error << std::endl;
        return;
    }

    UtilsTable().saveRawData(QUICK_SAVE_PATH);

    std::cout << DATA_SAVED_MESSAGE << std::endl;
}