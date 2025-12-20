#pragma once
#include <iostream>
#include <climits>

#include "dataStore/dataStore.h"
#include "commands/show/show.h"
#include "console.h"
#include "checkers.h"


extern std::vector<Student> studentsList;


void showEvent();

void addEvent();

void loadKeyboardEvent();

void editEvent();

void removeEvent();

void queryEvent();

void sortEvent();