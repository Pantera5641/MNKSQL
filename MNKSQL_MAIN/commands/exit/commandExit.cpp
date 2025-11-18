#include "commandExit.h"


void CommandExit::exit()
{
    CommandSave().save();
    std::exit(0);
}