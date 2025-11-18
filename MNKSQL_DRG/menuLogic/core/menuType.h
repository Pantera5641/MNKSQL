#pragma once
#include <string>

enum MenuType
{
    Main,
    Language,
    User,
    Admin,
    Unknown
};

std::string nameOf(MenuType menuType);