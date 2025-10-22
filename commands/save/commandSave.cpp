#include "commandSave.h"


void CommandSave::save()
{
    UtilsTable().saveRawData(QUICK_SAVE_PATH);

    std::cout << DATA_SAVED_MESSAGE << std::endl;
}