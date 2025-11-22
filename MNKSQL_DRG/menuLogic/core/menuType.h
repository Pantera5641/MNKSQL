#pragma once
#include <string>

enum MenuType
{
    Main,
    Language,
    User,
    UserLoad,
    Admin
};

std::string nameOf(MenuType menuType);