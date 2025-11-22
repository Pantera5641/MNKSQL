#pragma once
#include <string>

enum MenuType
{
    Main,
    Language,
    User,
    UserLoad,
    Admin,
    AdminLoad,
    Save
};

std::string nameOf(MenuType menuType);