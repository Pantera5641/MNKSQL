#pragma once
#include <string>

enum MenuType
{
    Main,
    Language,
    Unknown
};

std::string nameOf(MenuType menuType);