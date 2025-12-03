#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "helper/helper.h"
#include "..\constants\paths.h"


std::string getParam(const std::string& paramName, const std::string& path = CONFIG_PATH);

void setParam(const std::string& paramName, const std::string& newParam);