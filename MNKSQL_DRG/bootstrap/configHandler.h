#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "utils/helper.h"
#include "..\constants\paths.h"


std::string getParam(const std::string& paramName);

void setParam(const std::string& paramName, const std::string& newParam);