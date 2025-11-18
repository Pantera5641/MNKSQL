#pragma once
#include <string>

enum MenuType
{
    Main,
    Language,
    User,
    Unknown
};

std::string nameOf(MenuType menuType);