#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "messages.h"

struct CommandView
{
    private:
    enum Commands
    {
        Filter,
        Sort,
        Unknown
    };

    Commands strToAction(const std::string& str);

    void filter(const std::string& arg);

    void sort(const std::string& column, const std::string& typeOfSort);

    public:
    void execute(const std::vector<std::string>& items);
};