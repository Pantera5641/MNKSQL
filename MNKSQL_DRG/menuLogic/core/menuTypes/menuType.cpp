#include "menuType.h"


std::string nameOf(MenuType menuType)
{
    if (menuType == MenuType::Main) return "main";
    if (menuType == MenuType::Language) return "language";
    if (menuType == MenuType::User) return "user";
    if (menuType == MenuType::UserLoad) return "userLoad";
    if (menuType == MenuType::Admin) return "admin";
    if (menuType == MenuType::AdminLoad) return "adminLoad";
    if (menuType == MenuType::Save) return "save";
    if (menuType == MenuType::Convert) return "convert";
    return "unknown";
}