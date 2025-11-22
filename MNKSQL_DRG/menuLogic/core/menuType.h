#pragma once
#include <string>

enum MenuType
{
    Main,
    Language,
    User,
    UserLoad,
    Admin,
    AdminLoad
};

std::string nameOf(MenuType menuType);