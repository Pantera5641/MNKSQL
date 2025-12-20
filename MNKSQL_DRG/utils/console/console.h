#pragma once
#include <iostream>
#include <fstream>
#include <vector>

#include "menuType.h"
#include "../MNKSQL_DRG/constants/paths.h"
#include "helper/helper.h"

extern std::string globalLanguage;


void show(const std::string& path);

void show(const std::string& path, const std::string& color);

void showMenu(const std::string& title, const std::vector<std::string>& fields);

void showMenu(MenuType menuType);

void showLine(const std::string& lineName);

void clear();

void await(bool offIgnore = false);