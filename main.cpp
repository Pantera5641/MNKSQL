#include <iostream>

#include "startMain.h"
#include "startDrg.h"

#if _WIN32
#include <windows.h>
#endif


int main()
{
    #if _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    #else
    std::locale::global(std::locale("C.UTF-8"))
    std::wcout.imbue(std::locale())
    #endif

    std::string input {};

    while (true) 
    {
        std::cout << "Чтобы запустить MNKSQL-MAIN, введите \"Start Main\"" << std::endl;

        std::cout << "\033[0;31m";
        std::cout << "Внимание: эта версия не соответствует требованиям выполнения УТП!" << std::endl;
        std::cout << "Внимание 2: версия сырая и незаконченная!" << std::endl;
        std::cout << "\033[0m";

        std::cout << "или" << std::endl;
        std::cout << "Чтобы запустить MNKSQL-DRG, введите \"2\"" << std::endl;

        std::getline(std::cin, input);
        std::cout << "\033c";

        if (input == "Start Main")
            startMain();

        if (input == "2")
            startDrg();
    }
}