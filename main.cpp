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
        std::cout << "To start MNKSQL-MAIN enter \"Start Main\"" << std::endl;
        std::cout << "Attention does not meet the limits" << std::endl;
        std::cout << "or" << std::endl;
        std::cout << "To start MNKSQL-DRG enter \"2\"" << std::endl;

        std::cin >> input;
        std::cout << "\033c";

        if (input == "Start Main")
            startMain();

        if (input == "2")
            startDrg();
    }
}