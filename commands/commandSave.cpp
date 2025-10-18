#include "commandSave.h"


void CommandSave::save()
{
    UtilsFile().saveRawData(HOT_SAVE_PATH);

    std::cout << "Data saved" << std::endl;
}