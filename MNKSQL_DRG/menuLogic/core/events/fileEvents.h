#pragma once
#include <iostream>

#include "dataStore/dataStore.h"
#include "commands/file/file.h"
#include "configHandler.h"
#include "console.h"
#include "checkers.h"


extern std::vector<Student> studentsList;


void saveEvent(bool binaryMode = false);

void loadTxtEvent();

void loadBinEvent();

void convertTxtToBinEvent();

void convertBinToTxtEvent();