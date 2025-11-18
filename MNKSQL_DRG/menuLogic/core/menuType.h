#pragma once
#include <string>

enum MenuType
{
    Main,
    Language,
    User,
    Admin
};

std::string nameOf(MenuType menuType);