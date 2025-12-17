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

void showMenu(const std::string& title, const std::vector<std::string>& fields)
{
    const int width {78};
    int repeatCount {};

    std::cout << repeat(width, ':') << std::endl;

    repeatCount = (width - utf8Length(title) - 4) / 2;
    if ((utf8Length(title)) % 2 == 0) 
    {
        std::cout 
        << repeat(repeatCount, ':') 
        << repeat(2, ' ')
        << title
        << repeat(2, ' ')
        << repeat(repeatCount, ':') << std::endl;
    }
    else 
    {
        std::cout 
        << repeat(repeatCount, ':') 
        << repeat(2, ' ')
        << title
        << repeat(3, ' ')
        << repeat(repeatCount, ':') << std::endl;
    }
     
    std::cout << repeat(width, ':') << std::endl;

    for (int i = 0; i < fields.size(); i++) 
    {
        repeatCount = (width - utf8Length(fields.at(i)) - 4) / 2;
        if ((utf8Length(fields.at(i))) % 2 == 0) 
        {
            std::cout 
            << repeat(2, ':') 
            << repeat(repeatCount, ' ')
            << fields.at(i)
            << repeat(repeatCount, ' ')
            << repeat(2, ':') << std::endl;
        }
        else 
        {
            std::cout 
            << repeat(2, ':') 
            << repeat(repeatCount, ' ')
            << fields.at(i)
            << repeat(repeatCount + 1, ' ')
            << repeat(2, ':') << std::endl;
        }
    }

    std::cout << repeat(width, ':') << std::endl;
}

void showMenu(MenuType menuType)
{   
    std::string path {TO_LOCALIZATION_PATH + globalLanguage + "/menu/" + nameOf(menuType) + ".txt"};

    std::fstream file(path, std::ios::in);
    std::string str {};

    std::string title {};
    std::vector<std::string> fields {};

    while (std::getline(file, str)) 
    {
        if (title == std::string()) 
        {
            title = str;
        }
        else 
        {
            fields.push_back(str);
        }
    }
    
    showMenu(title, fields);
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