#include "commandSave.h"


void CommandSave::save()
{
    UtilsTable().saveRawData(QUICK_SAVE_PATH);

    std::cout << "Data saved" << std::endl;
}