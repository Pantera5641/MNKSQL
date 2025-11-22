#include "console.h"


void show(const std::string& path)
{
    std::string line {};
    std::fstream file(path, std::ios::in);

    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }
}

void show(const std::string& path, const std::string& color)
{
    std::cout << color;
    show(path);
    std::cout << "\033[0m" << std::endl;
}

void showMenu(MenuType menuType, const std::string& language)
{
    show("MNKSQL_DRG/data/menu/" + language + '/' + nameOf(menuType) + ".txt");
}

void clear()
{
    std::cout << "\033c";
}