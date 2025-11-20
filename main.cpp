#include <iostream>

#include "startMain.h"
#include "startDrg.h"


int main()
{
    std::string input {};
    std::cin >> input;
    std::cout << "\033c";

    if (std::stoi(input) == 0)
        startMain();

    startDrg();
}