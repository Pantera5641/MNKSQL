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
    show("MNKSQL_DRG/data/localization/" + language + "/menu/" + nameOf(menuType) + ".txt");
}

void showLine(const std::string& lineName, const std::string& language)
{
    show("MNKSQL_DRG/data/localization/" + language + "/lines/" + lineName + ".txt");
}

void clear()
{
    std::cout << "\033c";
}

void await()
{
    std::cout << "\033[1;37m";
    std::cout << "Press any button to continue..." << std::endl;
    std::cout << "\033[0m" << std::endl;
    std::cin.ignore();
    std::cin.get();
}