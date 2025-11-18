#include "menuType.h"


std::string nameOf(MenuType menuType)
{
    if (menuType == MenuType::Main) return "main";
    if (menuType == MenuType::Language) return "language";
    if (menuType == MenuType::User) return "user";
    if (menuType == MenuType::Admin) return "admin";
    if (menuType == MenuType::Unknown) return "unknown";
    return "unknown";
}