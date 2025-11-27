#include <iostream>

#include "dataStore/dataStore.h"
#include "commands/show/show.h"
#include "commands/file/file.h"
#include "console.h"


extern std::vector<Student> studentsList;


void showEvent();

void addEvent();

void editEvent();

void removeEvent();

void queryEvent();

void sortEvent();

void saveTxtEvent();

void saveBinEvent();

void loadKeyboardEvent();

void loadTxtEvent();

void loadBinEvent();

void convertTxtToBinEvent();

void convertBinToTxtEvent();