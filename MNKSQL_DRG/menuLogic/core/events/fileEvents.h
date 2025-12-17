#include <iostream>

#include "dataStore/dataStore.h"
#include "commands/file/file.h"
#include "console.h"
#include "checkers.h"


extern std::vector<Student> studentsList;


void saveTxtEvent();

void saveBinEvent();

void loadTxtEvent();

void loadBinEvent();

void convertTxtToBinEvent();

void convertBinToTxtEvent();