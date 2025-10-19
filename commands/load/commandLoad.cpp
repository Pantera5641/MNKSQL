#include "commandLoad.h"


void CommandLoad::load()
{
    UtilsFile().loadRawData(QUICK_SAVE_PATH);

    std::cout << "Data loaded" << std::endl;
}