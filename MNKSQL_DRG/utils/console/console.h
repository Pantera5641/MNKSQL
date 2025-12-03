#pragma once
#include <iostream>
#include <fstream>

#include "menuType.h"
#include "..\MNKSQL_DRG\constants\paths.h"

extern std::string globalLanguage;


void show(const std::string& path);

void show(const std::string& path, const std::string& color);

void showMenu(MenuType menuType);

void showLine(const std::string& lineName);

void clear();

void await(bool offIgnore = false);