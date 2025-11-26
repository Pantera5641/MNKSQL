#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include "dataStore/dataStore.h"


std::string repeat(int num, char item);

std::string cutAfter(const std::string& line, char item);

std::string cutBefore(const std::string& line, char item);

std::vector<int> strip(const std::string& str, char toRemove);

void bubbleSort(int index, std::vector<Student>& list);