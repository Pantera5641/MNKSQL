#include <iostream>
#include <vector>
#include <fstream>

#include "dataStore.h"
#include "..\MNKSQL_DRG\constants\paths.h"
#include "helper/helper.h"


void saveTxt(const std::string& fileName);

void saveBin(const std::string& fileName);

std::vector<std::string> loadTxt(const std::string& fileName);

std::vector<std::string> loadBin(const std::string& fileName);