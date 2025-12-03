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

void showMenu(MenuType menuType)
{
    show(TO_LOCALIZATION_PATH + globalLanguage + "/menu/" + nameOf(menuType) + ".txt");
}

void showLine(const std::string& lineName)
{
    show(TO_LOCALIZATION_PATH + globalLanguage + "/messages/" + lineName + ".txt");
}

void clear()
{
    std::cout << "\033c";
}

void await(bool offIgnore)
{
    std::string path {TO_LOCALIZATION_PATH + globalLanguage + "/messages/await.txt"};
    show(path, "\033[1;37m");
    
    if (offIgnore == false) 
        std::cin.ignore();
    std::cin.get();
}