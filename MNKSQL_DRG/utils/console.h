#pragma once
#include <iostream>
#include <fstream>

#include "menuType.h"


void show(const std::string& path);

void show(const std::string& path, const std::string& color);

void showMenu(MenuType menuType, const std::string& language);

void clear();

void await();