#include "commandSave.h"


void CommandSave::save()
{
    UtilsFile().saveRawData(QUICK_SAVE_PATH);

    std::cout << "Data saved" << std::endl;
}